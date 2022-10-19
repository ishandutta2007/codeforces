#include <bits/stdc++.h>
using namespace std;

int cnt[3];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  for (char c: s) {
    if (c == 'B') cnt[0]++;
    if (c == 'G') cnt[1]++;
    if (c == 'R') cnt[2]++;
  }
  for (int i = 0; i < 3; i++) {
    int x = cnt[i%3];
    int y = cnt[(i+1)%3];
    int z = cnt[(i+2)%3];
    bool ok = 0;
    if (y > 0 && z > 0) ok = 1;
    if (x > 0 && max(y, z) > 1) ok = 1;
    if (y == 0 && z == 0) ok = 1;
    if (ok) cout << "BGR"[i];
  }
  cout << '\n';
}