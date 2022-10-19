#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  string s;
  cin >> s;
  set<string> books;
  for (int i = 0; i <= (int)s.size(); i++) {
    for (char c = 'a'; c <= 'z'; c++) {
      string t = s.substr(0, i) + c + s.substr(i);
      books.insert(t);
    }
  }
  cout << books.size() << '\n';
}