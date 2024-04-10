#include <iostream>
#include <string>

using namespace std;

const int ALPHA = 128;

char succ [ALPHA], pred [ALPHA];
bool seen [ALPHA];

int main () {
  int stringc;
  cin >> stringc;

  for (int i = 0; i < stringc; i++) {
    string s;
    cin >> s;

    for (int j = 0; j < (int) s.size() - 1; j++) {
      if (succ[s[j]] != 0 && succ[s[j]] != s[j + 1]) {
        cout << "NO" << endl;
        return 0;
      }
      succ[s[j]] = s[j + 1];

      if (pred[s[j + 1]] != 0 && pred[s[j + 1]] != s[j]) {
        cout << "NO" << endl;
        return 0;
      }
      pred[s[j + 1]] = s[j];

      seen[s[j]] = 1;
    }
    seen[s.back()] = 1;
  }

  int cnta = 0, cntb = 0;
  for (int i = 'a'; i <= 'z'; i++) {
    if (seen[i]) {
      cnta++;
    }

    if (pred[i] == 0 && seen[i]) {
      for (int j = i; j != 0; j = succ[j]) {
        cntb++;
      }
    }
  }

  if (cnta != cntb) {
    cout << "NO" << endl;
    return 0;
  }

  for (int i = 'a'; i <= 'z'; i++) {
    if (pred[i] == 0 && seen[i]) {
      for (int j = i; j != 0; j = succ[j]) {
        cout << (char) j;
      }
    }
  }
  cout << endl;
}