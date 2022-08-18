#include <iostream>
#include <string>

using namespace std;

bool can (string num, int csum) {
  int cur = 0;
  for (char c : num) {
    cur += c - '0';
    if (cur > csum) {
      return false;
    }
    if (cur == csum) {
      cur = 0;
    }
  }

  if (cur == 0) {
    return true;
  } else {
    return false;
  }
}

int main () {
  int length;
  cin >> length;

  string num;
  cin >> num;

  int sum = 0;
  for (int i = 0; i < length; i++) {
    sum += num[i] - '0';
  }

  if (sum == 0) {
    cout << "YES" << '\n';
    return 0;
  }

  for (int i = 1; i <= sum / 2; i++) {
    if (sum % i == 0) {
      if (can(num, i)) {
        cout << "YES" << '\n';
        return 0;
      }
    }
  }
  cout << "NO" << '\n';
  return 0;
}