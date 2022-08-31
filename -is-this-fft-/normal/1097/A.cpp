#include <iostream>
#include <string>

using namespace std;

bool can (string s, string t) {
  return s[0] == t[0] || s[1] == t[1];
}

int main () {
  string src;
  cin >> src;

  for (int i = 0; i < 5; i++) {
    string t;
    cin >> t;

    if (can(src, t)) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}