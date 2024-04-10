#include "bits/stdc++.h"

using namespace std;

int main() {
  int n;
  cin >> n;

  string color = "blue";
  bool locked = false;

  while (n--) {
    string s;
    cin >> s;
    if (s == "lock") {
      locked = true;
    } else if (s == "unlock") {
      locked = false;
    } else if (!locked) {
      color = s;
    }
  }

  cout << color << "\n";
  return 0;
}