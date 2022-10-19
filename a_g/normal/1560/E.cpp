#include <math.h>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

string answer(string t);
string polycarp(string s, string removal);

int main () {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    string t;
    cin >> t;
    cout << answer(t) << "\n";
  }
}

string answer (string t) {
  map<char, int> freqs;
  string removal;
  for (int j = t.length() - 1; j >= 0; j--) {
    char c = t[j];
    if (removal.find(c) == std::string::npos) {
      removal = c + removal;
      freqs[c] = 1;
    }
    else {
      freqs[c] += 1;
    }
  }
  int pref_length = 0;
  for (int j = 0; j < removal.length(); j++) {
    char c = removal[j];
    if (freqs[c] % (j+1) != 0) {
      return "-1";
    }
    else {
      pref_length += freqs[c] / (j+1);
    }
  }
  string s = t.substr(0, pref_length);
  if (polycarp(s, removal) == t) {
    return s + " " + removal;
  }
  return "-1";
}

string polycarp(string s, string removal) {
  string result = "";
  for (char const &c: removal) {
    result += s;
    s.erase(remove(s.begin(), s.end(), c), s.end());
  }
  return result;
}