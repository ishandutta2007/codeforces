#include <iostream>
#include <vector>

using namespace std;

bool is_power_of_two (int num) {
  while (num % 2 == 0) {
    num /= 2;
  }

  return num == 1;
}

int main () {
  int length;
  cin >> length;

  /* "= 0" */
  if (length % 2 == 1) {
    cout << "NO" << endl;
  } else {
    vector<int> match (length + 1, 0);

    for (int k = 1 << 25; k != 1; k /= 2) {
      for (int j = 0;
           ((k + j <= length) &&
            (k - j - 1 >= 1) &&
            (match[k + j] == 0) &&
            (match[k - j - 1] == 0)); j++) {
        match[k + j] = k - j - 1;
        match[k - j - 1] = k + j;
      }
    }

    cout << "YES" << endl;
    for (int i = 1; i <= length; i++) {
      cout << match[i] << ' ';
    }
    cout << endl;
  }

  /* "!= 0" */
  if (length < 6) {
    cout << "NO" << endl;
  } else if (is_power_of_two(length)) {
    cout << "NO" << endl;
  } else if (length % 2 == 0) {
    vector<int> numbers;
    for (int i = 2; i <= length; i++) {
      if (i != length - 1) {
        numbers.push_back(i);
      }
    }

    vector<int> match (length + 1, 0);
    match[1] = length - 1;
    match[length - 1] = 1;
    for (int i = 0; i < (int) numbers.size(); i += 2) {
      match[numbers[i]] = numbers[i + 1];
      match[numbers[i + 1]] = numbers[i];
    }
    
    cout << "YES" << endl;
    for (int i = 1; i <= length; i++) {
      cout << match[i] << ' ';
    }
    cout << endl;
  } else if (length % 2 == 1) {
    vector<int> match (length + 1, 0);
    match[1] = 3;
    match[2] = 6;
    match[3] = 7;
    match[4] = 5;
    match[5] = 4;
    match[6] = 2;
    match[7] = 1;

    for (int i = 8; i <= length; i += 2) {
      match[i] = i + 1;
      match[i + 1] = i;
    }

    cout << "YES" << endl;
    for (int i = 1; i <= length; i++) {
      cout << match[i] << ' ';
    }
    cout << endl;
  }
}