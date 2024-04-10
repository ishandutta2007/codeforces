#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    string t = s;
    sort(t.begin(), t.end());
    t.resize(unique(t.begin(), t.end())-t.begin());
    int k = t.size();
    bool good = 1;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] != s[i%k]) good = 0;
    }
    cout << (good ? "YES" : "NO") << '\n';
  }
}