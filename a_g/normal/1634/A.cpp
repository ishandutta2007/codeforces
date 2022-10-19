#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    string s;
    cin >> n >> k >> s;
    string t = s;
    reverse(t.begin(), t.end());
    cout << ((s == t || !k) ? 1 : 2) << '\n';
  }
}