#include <bits/stdc++.h>

using namespace std;

const int LG = 31;
const int N = 200010;

int n, a[N], tmp[LG][N], cur[LG];

int msb (int x) {
  int res = LG; 
  while (res--) if (x & 1 << res) return res;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    a[i] ^= a[i - 1];
    int yo = a[i], nxt = msb(yo);
    if (yo) tmp[nxt][cur[nxt]++] = yo;
  }
  if (!a[n]) return puts("-1");
  int ans = 0;
  for (int i = LG - 1; i >= 0; --i) {
    if (cur[i] == 0) continue;
    ++ans;
    for (int j = 1; j < cur[i]; ++j) {
      if (tmp[i][j] != tmp[i][0]) {
        int yo = tmp[i][j] ^ tmp[i][0], nxt = msb(yo);
        if (yo) tmp[nxt][cur[nxt]++] = yo;
      } 
    }
  }
  cout << ans << '\n';
  return 0;
}