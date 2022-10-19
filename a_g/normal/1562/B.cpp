#include <bits/stdc++.h>
using namespace std;

int main () {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int k;
    string s;
    cin >> k >> s;
    int threes = 0;
    for (int j = 0; j < s.size(); j++) {
      if (s[j] == '3') {
        threes++;
      }
    }

    if (s.find('4') != string::npos) {
      cout << '1' << endl << '4' << endl;
    }
    else if (s.find('6') != string::npos) {
      cout << '1' << endl << '6' << endl;
    }
    else if (s.find('8') != string::npos) {
      cout << '1' << endl << '8' << endl;
    }
    else if (s.find('9') != string::npos) {
      cout << '1' << endl << '9' << endl;
    }
    else if (s.find('1') != string::npos) {
      cout << '1' << endl << '1' << endl;
    }
    else if (threes >= 2) {
      cout << '2' << endl << "33" << endl;
    }
    else {
      bool done = false;
      for (int j = 1; j < s.size(); j++) {
        if (s[j] == '2' || s[j] == '5') {
          cout << '2' << endl << s[0] << s[j] << endl;
          done = true;
          break;
        }
      }

      if (!done) {
        if (s[0] == '2' || s[0] == '5') {
          cout << '2' << endl << s[0] << '7' << endl;
        }
        else {
          cout << '2' << endl << "77" << endl;
        }
      }
    }
  }
}