#include <bits/stdc++.h>

using namespace std;

int main() {
  set <char> s;
  char c;
  while (cin >> c) {
    if (c != '{' && c != '}' && c != ',') {
      s.insert(c);
    }
  }
  cout << s.size() << endl;
}