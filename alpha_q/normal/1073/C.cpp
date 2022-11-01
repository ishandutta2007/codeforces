#include <bits/stdc++.h>

using namespace std;

#pragma GCC diagnostic warning "-std=c++11"

typedef long long ll;

const int N = 200010;

char s[N]; int n; ll x, y, px[N], py[N];

bool ok (int l) {
  ll xs = 0, ys = 0;
  for (int i = l + 1; i <= n; ++i) {
    if (s[i] == 'U') ++ys;
    if (s[i] == 'D') --ys;
    if (s[i] == 'L') --xs;
    if (s[i] == 'R') ++xs;
  }
  for (int i = 1, j = l; j <= n; ++i, ++j) {
      // cout << i << " " << j << endl;
      // cout << xs << " " << ys << endl;
      // cout << "--------------\n";
    if (l >= abs(x - xs) + abs(y - ys)) {
      // cout << i << " " << j << endl;
      // cout << xs << " " << ys << endl;
      return 1;
    }
    if (s[i] == 'U') ++ys;
    if (s[i] == 'D') --ys;
    if (s[i] == 'L') --xs;
    if (s[i] == 'R') ++xs;  
    if (s[j + 1] == 'U') --ys;
    if (s[j + 1] == 'D') ++ys;
    if (s[j + 1] == 'L') ++xs;
    if (s[j + 1] == 'R') --xs;  
  }
  return 0;
}

int main() {
  scanf("%d %s %lld %lld", &n, s + 1, &x, &y);
  ll curx = 0, cury = 0;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == 'U') ++cury;
    if (s[i] == 'D') --cury;
    if (s[i] == 'L') --curx;
    if (s[i] == 'R') ++curx;
    px[i] = curx, py[i] = cury;
  }
  if (curx == x and cury == y) {
    puts("0"); return 0;
  }
  ll yo = abs(x) + abs(y); 
  if (n < yo or n % 2 != yo % 2) {
    puts("-1"); return 0;
  }
  // cout << ok(2) << endl;
  int lo = 1, hi = n;
  while (lo < hi) {
    int mid = lo + hi >> 1;
    if (ok(mid)) hi = mid;
    else lo = mid + 1;
  }
  printf("%d\n", lo);
  return 0;
}