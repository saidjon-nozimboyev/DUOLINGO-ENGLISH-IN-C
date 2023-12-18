#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#define FILINAME_SIZE 1024
#define MAX_LINE 2048
#define MAX_USERS 100
#define MAX 100
struct Message {
  char from[50];
  char to[50];
  char message[100];
};

// registration qism
void login(int *mainWhile, int *getIn);
void registrated();
int checkengLevel(char level[]);
int checkBirthday(int birthDay, int birthMonth, int birthYear);
int checkName(char name[]);
int checkUsername_password(char user[]);
int checkEmail(char email[]);
int checkNumber(char number[]);
void typeMessage(struct Message *message);

void adminUsers();
void deleteUserFromFile(const char *filename, const char *userToDelete);
void deleteWordFromFile(const char *filename, char wordToDelete[20]);
void addword(const char *engfile, const char *uzfile, char engword[20],char uzword[20]);
void allwords(const char *uzfile, const char *engfile);
void sortingBirthdate(const char *filename);
void checkBirthday2(const char *filename);

void randomVocabulary();
void masRandIndexValue(int arr[], int size);
void matching_words(int line[4]);
void findLetter_10(char *output);
void matching_words2(int line[4]);
void printFrame() {
  printf("\t\t\t\t\t**************************************************\n");
  printf("\t\t\t\t\t*               DUOLINGO ENGLISH                 *\n");
  printf("\t\t\t\t\t**************************************************\n");
}
void printFrame2() {
menu:
  printf(
      "\t\t\t\t***********************************************************\n");
  printf(
      "\t\t\t\t*                                                         *\n");
  printf(
      "\t\t\t\t*                       MENU                              *\n");
  printf(
      "\t\t\t\t*                                                         *\n");
  printf(
      "\t\t\t\t*      1. Registration  2. Login  3. Admin  4. Exit       *\n");
  printf(
      "\t\t\t\t*                                                         *\n");
  printf(
      "\t\t\t\t***********************************************************\n");
}

// admin
int sezer() {
  char text[500], ch;
  FILE *fl = fopen("admin.txt", "r+");
  if (fl == NULL) {
    perror("Error code: ");
    return 0;
  }
  int key;

  // Taking user input.
  printf("Enter a login: ");
  scanf("%s", text);

  key = 17;

  for (int i = 0; text[i] != '\0'; ++i) {
    ch = text[i];

    if (isalnum(ch)) {
      if (islower(ch)) {
        ch = (ch - 'a' + key) % 26 + 'a';
      }
      if (isupper(ch)) {
        ch = (ch - 'A' + key) % 26 + 'A';
      }
      if (isdigit(ch)) {
        ch = (ch - '0' + key) % 10 + '0';
      }
    }
    else {
      printf("Invalid Message");
    }

    text[i] = ch;
  }

  char text2[655];
  fgets(text2, sizeof(text2), fl);

  if (strcmp(text2, text) == 0) {
    fclose(fl);
    return 1;
  }

  fclose(fl);
  return 0;
}

//                                       main
 int main(void) {
  const char *userToDelete;
  int mainWhile = 0;
  int adminCheck = 0;
  while (true) {
    // reg menu
    char choice;
    printFrame();
    printFrame2();
    printf("\nEnter your command: ");
    while (true) {
      scanf("%s", &choice);
      sleep(1);
      system("clear");
      if (choice >= 49 && choice <= 52) {
        break;
      } else {
        printf("Unclear command, select command again: ");
      }
    }
    int cmd = 0;
    if (choice == 49) {
      cmd = 1;
    } else if (choice == 50) {
      cmd = 2;
    } else if (choice == 51) {
      cmd = 3;
    } else {
      cmd = 4;
    }

    // switch tanlow
    int getIn = 0;
    switch (cmd) {
    case 1: {
      int choice;
      printf("\n\t\t\t\t\tLogin as a user or guest?\n");
      printf("\n\t\t\t\t\t\t1. User       2.Guest\n");

      printf("Enter your choice: ");
      scanf("%i", &choice);
      sleep(1);
      system("clear");
      if (choice == 1) {
        registrated();
      } else if (choice == 2) {
        goto game;
      }

      break;
    }
    case 2: {
      login(&mainWhile, &getIn);
      if (getIn == 1) {
        printFrame();
        printFrame2();
        printf("\n");
        printf("\t\t\t\t  "
               "******************************************************\n");
        printf("\t\t\t\t  *              You are re-registering                "
               "*\n");
        printf("\t\t\t\t  "
               "******************************************************\n");
      }

      break;
    }
    case 3: {
      adminUsers(&adminCheck);
      break;
    }
    case 4: {
      return 0;
    }
    }

    if (mainWhile) {
      break;
    }
  }

  int checkQuiz = 1;
game:
  while (checkQuiz) {
    printf("\n\t\t\t\t**************************************************************\n");
    printf("\t\t\t\t*                                                            *\n");
    printf("\t\t\t\t*                    🔡  DUOLINGO 🔡                         *\n");
    printf("\t\t\t\t*                                                            *\n");
    printf("\t\t\t\t🔸🔸🔸🔸🔸🔸🔸🔸🔸🔸🔸🔸🔸🔸🔸🔸🔸🔸🔸🔸🔸🔸🔸🔸🔸🔸🔸🔸🔸🔸🔸\n");
    printf("\t\t\t\t🔸                                                          🔸\n");
    printf("\t\t\t\t🔸                                                          🔸\n");
    printf("\t\t\t\t🔸          *********   MENU  *********                     🔸\n");
    printf("\t\t\t\t🔸                                                          🔸\n");
    printf("\t\t\t\t🔸       1. 4-word quiz                                     🔸\n");
    printf("\t\t\t\t🔸       2. Find a word by its letters                      🔸\n");
    printf("\t\t\t\t🔸       3. Matching wordd with their definitions           🔸\n");
    printf("\t\t\t\t🔸       4. Exit                                            🔸\n");
    printf("\t\t\t\t🔸                                                          🔸\n");
    printf("\t\t\t\t🔸                                                          🔸\n");
    printf("\t\t\t\t🔸🔸🔸🔸🔸🔸🔸🔸🔸🔸🔸🔸🔸🔸🔸🔸🔸🔸🔸🔸🔸🔸🔸🔸🔸🔸🔸🔸🔸🔸🔸\n");

    char choice2;
    printf("\n\t\t\t\t\t\t\t\tWELCOME TO DUOLINGO ENGLISH.\n");
    printf("\nEnter your command: ");
    while (true) {
      scanf("%s", &choice2);
      sleep(1);
      system("clear");
      if (choice2 >= 49 && choice2 <= 52) {
        break;
      } else {
        printf("Unclear command, select command again: ");
      }
    }
    int cnt = 0;
    if (choice2 == 49) {
      cnt = 1;
    } else if (choice2 == 50) {
      cnt = 2;
    } else if (choice2 == 51) {
      cnt = 3;
    } else {
      cnt = 4;
    }

    switch (cnt) {
    case 1: {
      int line[4];
      matching_words2(line);
      break;
    }
    case 2: {
      char output[1024];
      findLetter_10(output);
      break;
    }
    case 3: {
      int line[4];
      matching_words(line);
      break;
    }
    case 4: {
      printf("\nThanks for usung our app !");
      return 0;
    }
    }
  }

  return 0;
}

// reg qism
void registrated() {
  FILE *input_email = fopen("emails.txt", "a+");
  if (input_email == NULL) {
    perror("Error code Registration: ");
    return;
  }

  FILE *admin = fopen("admin.txt", "a+");
  if (admin == NULL) {
    perror("Error code admin: ");
    return;
  }

  int i = 2;
  char inputEmail[100];
  char inputNumber[100];
  char inputEngLevel[100];
  char inputUsername[100];
  char inputPassword[100];
  char inputName[100];
  int birthDay, birthMonth, birthYear;

  printf("Please enter your name: ");
  while (true) {
    scanf("%s", inputName);
    if (checkName(inputName) == 1) {
      break;
    } else {
      printf("\nThe name entered is invalid.\n");
      printf("Please re-enter your name: ");
    }
  }

  printf("Please enter your birth date (dd-mm-yyyy): ");
  while (true) {
    int result = scanf("%d-%d-%d", &birthDay, &birthMonth, &birthYear);
    if (result != 3 || !checkBirthday(birthDay, birthMonth, birthYear)) {
      printf("\nThe birth date entered is invalid.Please check format\n");
      printf("Please re-enter your birth date: ");
     
      while (getchar() != '\n')
        ;

      continue;
    }
    break;
  }

  printf("Please enter your email address: ");
  while (true) {
    scanf("%s", inputEmail);
    if (checkEmail(inputEmail) == 1) {
      break;
    } else {
      printf("\nThe email entered is invalid.\n");
      printf("Please re-enter your email address: ");
    }
  }

  printf("Enter your English proficiency level(ex: A1, C1): ");
  while (true) {
    scanf("%s", inputEngLevel);
    if (checkengLevel(inputEngLevel) == 1) {
      break;
    } else {
      printf("\nThere is no such level of English\n");
      printf("Please re-enter your English level: ");
    }
  }

  printf("Please enter phone number: (+998)");
  while (true) {
    scanf("%s", inputNumber);
    if (checkNumber(inputNumber) == 1) {
      break;
    } else {
      printf("\nThe number entered is invalid.\n");
      printf("Please re-enter your phone number: ");
    }
  }

  printf("Please enter your username: ");
  while (true) {
    scanf("%s", inputUsername);
    if (checkUsername_password(inputUsername) == 1) {
      break;
    } else {
      printf("\nThe username entered is invalid.\n");
      printf("Please re-enter your username: ");
    }
  }

  printf("Please enter your password: ");
  while (true) {
    scanf("%s", inputPassword);
    if (checkUsername_password(inputPassword) == 1) {
      break;
    } else {
      printf("\nThe password entered is invalid.\n");
      printf("Please re-enter your password: ");
    }
  }
  // fprint

  fprintf(input_email, "%15s | %.2i-%.2i-%.4i | %30s | %15s | %15s | %15s |\n",
          inputName, birthDay, birthMonth, birthYear, inputEmail, inputNumber,
          inputUsername, inputPassword);
  fprintf(admin, "%s | %d.%d.%d | %s | %s |\n", inputName, birthDay, birthMonth,
          birthYear, inputEngLevel, inputNumber);

  fclose(input_email);
  fclose(admin);
  printf("\nRegistration is complete.\n");
  sleep(1);
  system("clear");
}
void login(int *mainWhile, int *getIn) {
  int cnt = 0;
  while (true) {

    FILE *login_file = fopen("emails.txt", "r+");
    if (login_file == NULL) {
      perror("Error code login: ");
    }

    char inputEmail[100];
    char inputNumber[100];
    char inputUsername[100];
    char inputPassword[100];

    char reUsername[100];
    printf("\nEnter your username: ");
    scanf("%s", reUsername);
    char rePasswor[100];
    printf("Enter your password: ");
    scanf("%s", rePasswor);

    bool loggedIn = false;

    while (fscanf(login_file, "%30s | %15s | %15s | %15s", inputEmail,
                  inputNumber, inputUsername, inputPassword) != EOF) {
      if (strcmp(reUsername, inputUsername) == 0 &&
          strcmp(rePasswor, inputPassword) == 0) {
        fclose(login_file);
        loggedIn = true;

        printf("\nLogin success\n");
        *mainWhile = 1;
        sleep(1);
        system("clear");
        return;
        break;
      }
    }
    cnt++;
    if (cnt >= 2) {
      cnt = 0;
      char check;
      printf(
          "\t\t\t\t******************************************************\n");
      printf(
          "\t\t\t\t* Would you like to return to the registration menu? *\n");
      printf(
          "\t\t\t\t******************************************************\n");

      printf("\nY/N: ");
      scanf(" %c", &check);
      if (check == 'Y' || check == 'y') {
        sleep(1);
        system("clear");
        *getIn = 1;
        return;
      } else {
        continue;
      }
    }
    if (!loggedIn) {
      printf(
          "\n\t\t\t\t*   There is an error in the password or username    *\n");
    }
  }
}

// reg tekshiruv qismi
int checkEmail(char email[]) {

  for (int k = 0; k < strlen(email); k++) {
    if (isupper(email[k])) {
      return 0;
    }
    if (ispunct(email[k]) && (email[k] != '@' && email[k] != '.')) {
      return 0;
    }
  }

  int place = 0, dot = 0, place2 = 0, place3 = 0;
  int check = 0;
  char k = '@'; // find @ function
  for (int i = 0; email[i] != '@'; i++) {
    place++;
    if (email[0] >= 48 && email[0] <= 57) {
      return 0;
    }
  }
  //---------------------------------------------------------
  for (int i = 0; email[i] != '\0'; i++) { // check value of @
    place3++;
    if (email[i] == '@') {
      check++;
    }
  }
  if (check == 0 || check >= 2) {
    return 0;
  }
  for (int i = place + 1; email[i] != '.'; i++) { // check before dot
    dot++;
  }
  if (dot < 2) {

    return 0;
  }
  for (int i = 0; email[i] != '.'; i++) {
    place2++;
  }
  if (place + 1 < dot) {
    return 0;
  }
  if (place3 - place2 > 2) {

    return 1;
  } else {

    return 0;
  }
}
int checkNumber(char number[]) {
  if (strlen(number) < 9 || strlen(number) > 9) {
    return 0;
  }
  for (int i = 0; i < strlen(number); i++) {
    if (!(number[i] >= 48 && number[i] <= 57)) {
      return 0;
    }
  }
  return 1;
}
int checkUsername_password(char user[]) {
  if (strlen(user) < 8) {
    return 0;
  }
  int len = strlen(user);
  if (isdigit(user[0])) {
    return 0;
  }

  for (int i = 0; i < strlen(user); i++) {
    if (ispunct(user[i])) {
      return 0;
    }
  }
  return 1;
}
int checkName(char name[]) {
  if (strlen(name) <= 2) {
    return 0;
  }
  for (int i = 0; i < strlen(name); i++) {
    if (ispunct(name[i])) {
      return 0;
    }
  }
  return 1;
}
int checkBirthday(int birthDay, int birthMonth, int birthYear) {
  if (birthDay <= 0 || birthDay > 31) {
    return 0;
  } else if (birthMonth <= 0 || birthMonth > 12) {
    return 0;
  } else if (birthYear <= 1900) {
    return 0;
  } else {
    return 1;
  }
}
int checkengLevel(char level[]) {
  if (strlen(level) != 2) {
    return 0;
  }
  if (level[1] > 50 || level[1] < 49) {
    return 0;
  }
  if (!isupper(level[0]) || !isdigit(level[1]) || !isalpha(level[0]) ||
      level[0] > 'C') {
    return 0;
  } else {
    return 1;
  }
}

// admin login
void adminUsers(int *adminCheck) {
  while (true) {

    FILE *login_file = fopen("admin_user.txt", "r+");
    if (login_file == NULL) {
      perror("Error code login: ");
    }

    char inputEmail[100];
    char inputNumber[100];
    char inputUsername[100];
    char inputPassword[100];

    char reUsername[100];
    printf("\nEnter your username: ");
    scanf("%s", reUsername);
    char rePasswor[100];
    printf("Enter your password: ");
    scanf("%s", rePasswor);

    bool loggedIn = false;

    while (fscanf(login_file, "%30s | %15s | %15s | %15s\n", inputEmail,
                  inputNumber, inputUsername, inputPassword) != EOF) {
      if (strcmp(reUsername, inputUsername) == 0 &&
          strcmp(rePasswor, inputPassword) == 0) {
        fclose(login_file);
        loggedIn = true;
        printf("\nLogin success\n");
        sleep(1);
        system("clear");

        int ll = 1;
        while (ll) {
          printf("\n\t\t\t\t\t\tADMIN'S MENU\n\n");
          printf("\t\t◼️◼️ 1.Delete a user                  "
                 "◼️◼️\n");
          printf("\t\t◼️◼️ 2.See all words                  "
                 "◼️◼️\n");
          printf("\t\t◼️◼️ 3.Delete a word                  "
                 "◼️◼️\n");
          printf("\t\t◼️◼️ 4.Add a word                     "
                 "◼️◼️\n");
          printf("\t\t◼️◼️ 5.Sorting by birth year          "
                 "◼️◼️\n");
          printf("\t\t◼️◼️ 6.See whose birthday it is today "
                 "◼️◼️\n");
          printf("\t\t◼️◼️ 7.Write a message                "
                 "◼️◼️\n");
          printf("\t\t◼️◼️ 8.Exit admin menu                "
                 "◼️◼️\n\n\n");
          int cnt;
          printf("Enter a command: ");
          scanf("%d", &cnt);

          switch (cnt) {
          case 1: {
            const char *filename = "admin.txt";
            char userToDelete[20];
            printf("Enter the name of the user to delete: ");
            scanf("%19s", userToDelete);
            deleteUserFromFile(filename, userToDelete);
            break;
          }
          case 2: {
            const char *engfile = "simple_words.txt";
            const char *uzfile = "simple_words_uz.txt";
            allwords(engfile, uzfile);
            break;
          }
          case 3: {
            const char *filename = "simple_words.txt";
            char wordToDelete[20];
            printf("Please write a word you want to delete: ");
            scanf("%s", wordToDelete);
            deleteWordFromFile(filename, wordToDelete);
            break;
          }
          case 4: {
            char eng[20], uz[20];
            printf("Write an english word you want to add: ");
            scanf(" %s", eng);
            printf("Please write an uzbek translation of the word '%s': ", eng);
            scanf(" %s", uz);
            addword("simple_words.txt", "simple_words_uz.txt", eng, uz);
            break;
          }
          case 5: {
            const char *filename = "admin.txt";
            sortingBirthdate(filename);
            break;
          }
          case 6: {
            checkBirthday2("admin.txt");
            break;
          }
          case 7: {
            struct Message messages[MAX];
            int messageCnt = 0;
            typeMessage(&messages[messageCnt]);
            break;
          }
          case 8: {
            return;
            break;
          }
          default: {
            break;
          }
          }
        }
        return;
        break;
      }
    }

    if (!loggedIn) {
      printf("\nThere is an error in the password or username\n");
      printf("Please try again.\n");
    }
  }
}
void deleteUserFromFile(const char *filename, const char *userToDelete) {
  FILE *user = fopen(filename, "r");
  if (user == NULL) {
    printf("Failed to open the file.\n");
    return;
  }
  FILE *tempFile = fopen("temp.txt", "w");
  if (tempFile == NULL) {
    printf("Failed to create a temporary file.\n");
    fclose(user);
    return;
  }

  char username[20];
  int day = 0;
  int month = 0;
  int year = 0;
  char level[20];
  int correct_words;
  int userDeleted = 0;
  while (fscanf(user, "%s | %d.%d.%d | %s | %d |", username, &day, &month,
                &year, level, &correct_words) != EOF) {
    if (strcmp(username, userToDelete) == 0) {
      userDeleted = 1;
    } else {
      fprintf(tempFile, "%s | %d.%d.%d | %s | %d |\n", username, day, month,
              year, level, correct_words);
    }
  }

  fclose(user);
  fclose(tempFile);

  if (userDeleted) {
    if (remove(filename) == 0 && rename("temp.txt", filename) == 0) {
      printf("The user '%s' was successfully deleted.\n", userToDelete);
    } else {
      printf("Failed to delete the user.\n");
    }
  } else {
    printf("The user '%s' was not found.\n", userToDelete);
    remove("temp.txt");
  }
}
void deleteWordFromFile(const char *filename, char wordToDelete[20]) {
  // english word delete
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Failed to open the file.\n");
    return;
  }
  FILE *tempFile = fopen("temp.txt", "w");
  if (tempFile == NULL) {
    printf("Failed to create a temporary file.\n");
    fclose(file);
    return;
  }

  char word[100];
  int save_line = 0;
  int wordDeleted = 0;
  int cnt_line = 0;
  while (fscanf(file, "%s", word) != EOF) {
    if (strcmp(word, wordToDelete) == 0) {
      wordDeleted = 1;
      save_line = cnt_line;
    } else {
      fprintf(tempFile, "%s\n", word);
    }
    cnt_line++;
  }

  fclose(file);
  fclose(tempFile);

  if (wordDeleted) {
    if (remove(filename) == 0 && rename("temp.txt", filename) == 0) {
      printf("The word ➡️ %s ⬅️ was successfully deleted from the file",
             wordToDelete);
    } else {
      printf("Failed to delete the word from the file.\n");
    }
  } else {
    printf("The word '%s' was not found in the file.\n", wordToDelete);
    remove("temp.txt");
  }

  // uzbek word delete ->
  FILE *file2 = fopen("simple_words_uz.txt", "r");
  if (file2 == NULL) {
    printf("Failed to open the file.\n");
    return;
  }
  FILE *tempFile2 = fopen("temp2.txt", "w");
  if (tempFile2 == NULL) {
    printf("Failed to create a temporary file.\n");
    fclose(file2);
    return;
  }
  int cnt2 = 0, wordDeleted2;
  char word2[20];
  while (fscanf(file2, "%s", word2) != EOF) {
    if (save_line == cnt2) {
      wordDeleted2 = 1;
    } else {
      fprintf(tempFile2, "%s\n", word2);
    }
    cnt2++;
  }

  fclose(file2);
  fclose(tempFile2);

  if (wordDeleted2) {
    if (remove("simple_words_uz.txt") == 0 &&
        rename("temp2.txt", "simple_words_uz.txt") == 0) {
      printf("✅");
    } else {
      printf("Failed to delete the word from the file.\n");
    }
  } else {
    remove("temp2.txt");
  }
  ///////////////////////////////////////////
}
void addword(const char *engfile, const char *uzfile, char engword[20], char uzword[20]) {
  FILE *file1 = fopen(engfile, "a+");
  FILE *file2 = fopen(uzfile, "a+");
  fprintf(file1, "%s\n", engword);
  fprintf(file2, "%s\n", uzword);
  fclose(file1);
  fclose(file2);
  printf("The word '%s' was successfully added✅\n", engword);
}
void allwords(const char *engfile, const char *uzfile) {
  FILE *fleng = fopen(engfile, "r");
  if (fleng == NULL) {
    printf("Failed to open the file.\n");
    return;
  }
  FILE *fluz = fopen(uzfile, "r");
  if (fleng == NULL) {
    printf("Failed to open the file.\n");
    return;
  }
  char uz[50], eng[50];
  int cnt = 1;
  printf("\t\t\tDUOLINGO DICTIONARY\n\n");
  printf("%10s  | %10s\n", "English", "Uzbek");
  printf("--------------------------------------\n");
  while (fscanf(fleng, "%s", eng) != EOF && fscanf(fluz, "%s", uz) != EOF) {
    printf("|%2i|%15s | %16s|\n", cnt, eng, uz);
    printf("---------------------------------------\n");
    cnt++;
  }
  fclose(fleng);
  fclose(fluz);
}
void sortingBirthdate(const char *filename) {
  FILE *fl = fopen(filename, "r");
  if (fl == NULL) {
    printf("Failed to open the file.\n");
    return;
  }

  char name[30];
  int day, month, year;
  char level[3];
  int correct_words;
  int cnt = 0;

  while (fscanf(fl, "%s | %d.%d.%d | %s | %d |", name, &day, &month, &year,
                level, &correct_words) != EOF) {
    cnt++;
  }

  int y[cnt], m[cnt], d[cnt], i = 0;

  fseek(fl, 0, SEEK_SET);

  while (fscanf(fl, "%s | %d.%d.%d | %s | %d |", name, &day, &month, &year,
                level, &correct_words) != EOF) {
    y[i] = year;
    m[i] = month;
    d[i] = day;
    i++;
  }

  for (int j = 0; j < cnt - 1; j++) {
    for (int k = 0; k < cnt - j - 1; k++) {
      if (y[k] < y[k + 1] || (y[k] == y[k + 1] && m[k] < m[k + 1]) ||
          (y[k] == y[k + 1] && m[k] == m[k + 1] && d[k] < d[k + 1])) {
        int temp = y[k];
        y[k] = y[k + 1];
        y[k + 1] = temp;

        int temp1 = m[k];
        m[k] = m[k + 1];
        m[k + 1] = temp1;

        int temp2 = d[k];
        d[k] = d[k + 1];
        d[k + 1] = temp2;
      }
    }
  }
  fclose(fl);
  fl = fopen(filename, "r");
  int a = 0;
  while (fscanf(fl, "%s | %d.%d.%d | %s | %d |", name, &day, &month, &year,
                level, &correct_words) != EOF) {
    printf("%10s | %.2d.%.2d.%.2d | %5s | %10d |\n", name, d[a], m[a], y[a],
           level, correct_words);
    a++;
  }
  fclose(fl);
}

// eng games
void randomVocabulary() {
  srand(time(0));
  // file bilan ishlash
  FILE *file;
  char filename[FILINAME_SIZE] = "randEng.txt";
  char buffer[MAX_LINE];

  // qator holati
  int read_line = 0;

  // qatorni tanlash
  int n = 10;
  while (n) {
    n--;
    int check = rand() % 100;
    if (check % 2 != 0 && check < 70) {
      read_line = check;
      break;
    }
  }

  // fileni ochish
  file = fopen(filename, "r");

  // agar fayl ochilmasa
  if (file == NULL) {
    printf("Error opening file\n");
    return;
  }

  bool keep_reading = 1;
  int current_line = 1;

  // inglischa so'zlar uchun
  do {
    fgets(buffer, MAX_LINE, file);
    // feof filening oxirga qatorini qaytaradi
    // agar kiritilgan qiymat oxiridan katta bo'lsa 0 dan farqli son qaytaradi
    if (feof(file)) {
      keep_reading = false;
      printf("Random number has reached its limit.\n");
      printf("Maximum num: %d", current_line / 2);
    } else if (current_line == read_line) {
      keep_reading = false;
      printf("- %s", buffer);
    }
    current_line++;
  } while (keep_reading);

  // To'gri javobni olish
  char correct_answear[50];
  // return sign.txt uz
  do {
    fgets(buffer + 1, MAX_LINE, file);
    if (feof(file)) {
      keep_reading = false;
      printf("Error: Restart the program !\n");
    } else if (current_line == read_line + 1) {
      keep_reading = false;
      strcpy(correct_answear, buffer + 1);
    }
  } while (keep_reading);
  printf("%s", correct_answear);

  fclose(file);
}
void masRandIndexValue(int arr[], int size) {
  int k = 1;
  while (k) {
    int missingNumber = -1;

    for (int i = 0; i < size; i++) {
      if (arr[i] != missingNumber) {
        for (int j = i + 1; j < size; j++) {
          if (arr[i] == arr[j]) {
            arr[j] = missingNumber;
            break;
          }
        }
      }
    }

    for (int i = 0; i < size; i++) {
      if (arr[i] == missingNumber) {
        for (int j = 1; j <= size; j++) {
          int found = 0;
          for (int k = 0; k < size; k++) {
            if (arr[k] == j) {
              found = 1;
              break;
            }
          }
          if (!found) {
            arr[i] = j;
            break;
          }
        }
      }
    }

    int h = 1;
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        if (arr[i] == arr[j] && i != j) {
          h = 0;
        }
      }
    }

    if (h != 0) {
      k = 0;
    }
  }
}
void matching_words(int line[4]) {

  int uz_line[4];
  //====================
  srand(time(0));
  int arr[4];
  for (int i = 0; i < 4; i++) {
    arr[i] = rand() % 4;
  }
  int size = sizeof(arr) / sizeof(arr[0]);

  masRandIndexValue(arr, size);

  //=================

  srand(time(0));
  // save matrix
  char eng_mat[4][100];
  char uz_mat[4][100];

  for (int i = 0; i < 4; i++) {

    FILE *file;
    file = fopen("simple_words.txt", "r");
    FILE *file2;
    file2 = fopen("simple_words_uz.txt", "r");
    if (file == NULL) {
      printf("Error");
    }

    int num = rand() % 100;
    line[i] = num;

    int current_line = 1;
    char buffer[100];
    char buffer2[100];
    int current_line2 = 1;

    // eng matching
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
      if (current_line == num) {
        buffer[strcspn(buffer, "\n")] = '\0';
        strcpy(eng_mat[i], buffer);
        break;
      }
      current_line++;
    }

    // uz matching
    while (fgets(buffer2, sizeof(buffer2), file2) != NULL) {
      if (current_line2 == num) {
        uz_line[i] = num;
        strcpy(uz_mat[i], buffer2);
        break;
      }
      current_line2++;
    }

    fclose(file);
    fclose(file2);
  }

  int h;
  for (int i = 0; i < 4; i++) {
    int k = rand() % 4;
    if (h == k) {
      k = rand() % 4;
    }
    h = k;
    printf("\t\t\t%d. %-15s", i + 1, eng_mat[i]);
    printf("%d. %s", i + 1, uz_mat[arr[i]]);
  }

  int num1, cnt = 0;
  for (int i = 0; i < 4; i++) {
    printf("\n%s = ", eng_mat[i]);
    scanf("%d", &num1);
    if (i == arr[num1 - 1]) {
      cnt++;
    }
  }

  printf("\n ________________________________\n");
  printf("| Overall | Correct | Incorrect |\n");
  printf("| %8i|%9i|%11i|\n", 4, cnt, 4 - cnt);
  printf(" --------------------------------\n");

  // Tekshiruvga tushinish uchun bu qism

  // for(int i = 0; i < 4; i++){
  //   printf("\n%d ", arr[i]);
  // }
}
void findLetter_10(char *output) {
  int cnt = 0, cn_true = 0, cn_false = 0;
  printf("\n\t\t\t\t\t📍- Fill the word with a letter - 📍\n");
  printf("\t\t\t\t\t📍 - You will be given 10 words - 📍\n");

  int n = 10;
  while (n) {
    const char *filename = "simple_words.txt";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
      perror("Error: ");
      return;
    }

    int numLines = 0;
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
      numLines++;
    }
    rewind(file);

    // Random tanlov
    srand(time(0));
    int lineNumber = rand() % numLines;
    int currentLine = 0;

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
      if (currentLine == lineNumber) {
        buffer[strcspn(buffer, "\n")] = '\0';  
        strcpy(output, buffer);
        break;
      }
      currentLine++;
    }

    fclose(file);

    
    int len = strlen(output);
    int i22;
    do {
      i22 = rand() % len;
    } while (output[i22] == '#' || output[i22] == ' ');
    
    char check_words[50];
    check_words[0] = output[i22];
    output[i22] = '#';
    printf("\n%s\n", output);

    
    int attempts = len / 2;
    int i = 1;
    while (attempts) {
      char input_words[50];
      scanf("%s", input_words);

      if (strcmp(check_words, input_words) == 0) {
        cn_true++;
        cnt++;
        printf("\t\t\t⭐️ ⭐️ Good job! ⭐️ ⭐️ \n");
        break;
      } else {
        attempts--;
        printf("\t\tIncorrect, you have %d attempts left.\n", attempts);
        cn_false++;
        if (i) {
          cnt++;
          i = 0;
        }
      }
    }

    if (attempts == 0) {
      printf("\n\t\t 🔴 Unfortunately, you couldn't find the letter 🔴 :(\n\t\tThe correct answer -> %s\n",
             output);
    }

    sleep(1);
    system("clear");
    n--;
  }

  system("clear");
  printf("___________________________________________________________\n");
  printf("|     Attempts|   Correct answers|       Incorrect answers|\n");
  printf("|%13i|%18i|%24i|\n", cnt, cn_true, cn_false);
  printf(" ----------------------------------------------------------\n");
}
void matching_words2(int line[4]) {

  int uz_line[4];
  //====================
  srand(time(0));
  int arr[4];
  for (int i = 0; i < 4; i++) {
    arr[i] = rand() % 4;
  }
  int size = sizeof(arr) / sizeof(arr[0]);

  masRandIndexValue(arr, size);

  //=================

  srand(time(0));
  // save matrix
  char eng_mat[4][100];
  char uz_mat[4][100];

  for (int i = 0; i < 4; i++) {

    FILE *file;
    file = fopen("simple_words.txt", "r");
    FILE *file2;
    file2 = fopen("simple_words_uz.txt", "r");
    if (file == NULL) {
      printf("Error");
    }

    int num = rand() % 100;
    line[i] = num;

    int current_line = 1;
    char buffer[100];
    char buffer2[100];
    int current_line2 = 1;

    // eng matching
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
      if (current_line == num) {
        buffer[strcspn(buffer, "\n")] = '\0';
        strcpy(eng_mat[i], buffer);
        break;
      }
      current_line++;
    }

    // uz matching
    while (fgets(buffer2, sizeof(buffer2), file2) != NULL) {
      if (current_line2 == num) {
        uz_line[i] = num;
        strcpy(uz_mat[i], buffer2);
        break;
      }
      current_line2++;
    }

    fclose(file);
    fclose(file2);
  }
  char n = 'a';
  int cnt = 0;
  for (int h = 0; h < 4; h++) {
    printf("\t\t\t\t\t\t______________________\n");
    printf("\n\t\t\t\t\t\t\t%d. %-10s\n\n", h + 1, eng_mat[h]);
    printf("\t\t\t\t\t\t----------------------\n\n");
    for (int i = 0; i < 4; i++) {
      printf("\t\t\t\t\t\t\t%c. %s\n", n, uz_mat[arr[i]]);
      n++;
      if (n == 'e') {
        n = 'a';
      }
    }

    int num1 = 0;
    char ans;
    printf("\n\t\t\t\tEnter your answer (a, b, c, or d): ");
    scanf(" %c", &ans);

    switch (ans) {
    case 'a':
      num1 = 1;
      break;
    case 'b':
      num1 = 2;
      break;
    case 'c':
      num1 = 3;
      break;
    case 'd':
      num1 = 4;
      break;
    default:
      num1 = 0;
      break;
    }

    if (num1 != 0 && h == arr[num1 - 1]) {
      cnt++;
    }
    sleep(1);
    system("clear");
  }

  printf("\n\t\t\t\t ________________________________\n");
  printf("\t\t\t\t|  Total  | Correct | Incorrect |\n");
  printf("\t\t\t\t --------------------------------\n");
  printf("\t\t\t\t|%9i|%9i|%11i|\n", 4, cnt, 4 - cnt);
  printf("\t\t\t\t --------------------------------\n");
}
void checkBirthday2(const char *filename) {
  char username[100];
  int day, month, year, cnt = 0;
  char level[100];
  char phonenum[100];
  time_t current_time;
  time(&current_time);
  struct tm *current_date = localtime(&current_time);
  int current_month = current_date->tm_mon + 1;
  int current_day = current_date->tm_mday;
  FILE *fl = fopen(filename, "r");
  if (fl == NULL) {
    printf("Error opening file...\n");
    return;
  }
  printf("\t\t\t\tChecking whose birthday it is today...\n");
  sleep(2);
  system("clear");
  while (fscanf(fl, "%s | %d.%d.%d | %s | %s |", username, &day, &month, &year,
                level, phonenum) == 6) {
    if (current_month == month && current_day == day) {
      cnt++;
      printf("\t\t\tHappy birthday %s 🎊. Wish you all the best!\n\n",username);
    }
  }
  fclose(fl);
  if (cnt == 0) {
    printf("\t\t\t\tOops, we have no birthday party...\n");
  }
}
void typeMessage(struct Message *message) {
  printf("\nSender: ");
  scanf("%49s", message->from);
  printf("Recipient: ");
  scanf("%49s", message->to);
  printf("Message: ");
  scanf(" %[^\n]", message->message);
  printf("\nThe message was successfully sent ✅\n");
}
