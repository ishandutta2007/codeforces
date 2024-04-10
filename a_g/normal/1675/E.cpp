#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int v[26];
    iota(v, v+26, 0);
    for (char c: s) {
      int x = c-'a';
      while (k && v[x]) {
        k--;
        v[x] = v[v[x]-1];
      }
      for (int i = 24; i >= 0; i--) {
        v[i] = min(v[i], v[i+1]);
      }
      cout << (char)(v[x]+'a');
    }
    cout << '\n';
  }
}