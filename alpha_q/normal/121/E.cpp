#include <bits/stdc++.h>

using namespace std;

const int B = 3000;
const int M = 10005;
const int N = 100005;
const int T = (N + B - 1)/B;

char cmd[10];
vector <int> lucky;
int n, m, a[N], f[T][M], lazy[T];
int block[N], start[T], _end[T], isLucky[M];

void generate (int dig) {
  for (int mask = 0; mask < 1 << dig; ++mask) {
    int now = 0;
    for (int j = 0; j < dig; ++j) {
      now *= 10;
      if (mask & 1 << j) now += 4;
      else now += 7; 
    }  
    lucky.push_back(now);
  }
}

int main() {
  for (int i = 1; i <= 4; ++i) {
    generate(i);
  }
  for (int x : lucky) {
    isLucky[x] = 1;
  }
  scanf("%d %d", &n, &m);
  for (int i = 0, j = -1; i < n; ++i) {
    scanf("%d", a + i);
    if (i % B == 0) {
      block[i] = ++j;
      start[block[i]] = i;
      _end[block[i]] = min(i + B - 1, n - 1);
    } else {
      block[i] = j;
    }
    ++f[block[i]][a[i]];
  }
  while (m--) {
    scanf("%s", cmd);
    if (cmd[0] == 'a') {
      int l, r, d;
      scanf("%d %d %d", &l, &r, &d);
      --l, --r;
      if (block[l] == block[r]) {
        for (int i = l; i <= r; ++i) {
          --f[block[i]][a[i]];
          ++f[block[i]][a[i] + d];
          a[i] += d;
        }
      } else {
        for (int i = l; i <= _end[block[l]]; ++i) {
          --f[block[i]][a[i]];
          ++f[block[i]][a[i] + d];
          a[i] += d;
        }
        for (int i = start[block[r]]; i <= r; ++i) {
          --f[block[i]][a[i]];
          ++f[block[i]][a[i] + d];
          a[i] += d;
        }
        for (int i = block[l] + 1; i < block[r]; ++i) {
          lazy[i] += d;
        }
      }
    } else {
      int l, r, ans = 0;
      scanf("%d %d", &l, &r);
      --l, --r;
      if (block[l] == block[r]) {
        for (int i = l; i <= r; ++i) {
          ans += isLucky[a[i] + lazy[block[i]]];
        }
      } else {
        for (int i = l; i <= _end[block[l]]; ++i) {
          ans += isLucky[a[i] + lazy[block[i]]];
        }
        for (int i = start[block[r]]; i <= r; ++i) {
          ans += isLucky[a[i] + lazy[block[i]]];
        }
        for (int x : lucky) {
          for (int i = block[l] + 1; i < block[r]; ++i) {
            if (x >= lazy[i]) {
              ans += f[i][x - lazy[i]];
            }
          }
        }
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}