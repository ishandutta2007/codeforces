#include <iostream>

using namespace std;

int cnt [200];

int main () {
  int length;
  cin >> length;

  if (length == 1) {
    cout << "Yes" << endl;
    return 0;
  }
  
  for (int i = 0; i < length; i++) {
    char let;
    cin >> let;

    cnt[let]++;
  }

  for (int i = 'a'; i <= 'z'; i++) {
    if (cnt[i] >= 2) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  return 0;
}