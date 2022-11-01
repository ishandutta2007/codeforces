#include <bits/stdc++.h>

using namespace std;

int n;
string s;

bool isVowel (char c) {
  return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
}

vector <string> v;

bool isBad (string &x) {
  int sz = x.size();
  for (int i = 0; i < sz - 2; ++i) {
    if (!(x[i] == x[i + 1] and x[i + 1] == x[i + 2])) {
      if (!isVowel(x[i]) and !isVowel(x[i + 1]) and !isVowel(x[i + 2])) {
        return 1;
      }
    }
  }
  return 0;
}

int main() {
  cin >> s;
  n = s.size();
  string cur = "";
  for (int i = 0; i < n; ++i) {
    string nxt = cur + s[i];
    if (isBad(nxt)) {
      cout << cur << " ";
      cur = s[i]; 
    } else {
      cur += s[i];
    }
  }
  cout << cur << endl;
  return 0;
}