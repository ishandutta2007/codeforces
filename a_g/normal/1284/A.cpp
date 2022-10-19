#include <bits/stdc++.h>
using namespace std;

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> s(n), t(m);
  for (string& x: s) cin >> x;
  for (string& x: t) cin >> x;
  int q;
  cin >> q;
  while (q--) {
    int y;
    cin >> y;
    cout << s[(y-1)%n] << t[(y-1)%m] << '\n';
  }
}