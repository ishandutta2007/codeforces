#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    set<char> z;
    for (char c: s) z.insert(c);
    cout << n+z.size() << '\n';
  }
}