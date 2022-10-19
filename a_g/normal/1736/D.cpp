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
    vector<int> a;
    bool b = 0;
    for (int i = 0; i < 2*n; i += 2) {
      if (s[i] != s[i+1]) {
        if (b^(s[i] == '0')) a.push_back(i);
        else a.push_back(i+1);
        b ^= 1;
      }
    }
    if (a.size()&1) {
      cout << "-1\n";
      continue;
    }
    cout << a.size();
    for (int x: a) cout << ' ' << x+1;
    cout << '\n';
    for (int i = 1; i < 2*n; i += 2) {
      cout << i << ' ';
    }
    cout << '\n';
  }
}