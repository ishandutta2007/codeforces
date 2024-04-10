#include <bits/stdc++.h>

using namespace std;

const int N = 22;

int t, fin;
long long n;
int f[N][N];
int good[] = {0, 4, 7};
int goal[N];
long long ans[N];

int call (int at, int carry) {
  if (at == fin) {
    return carry == 0;
  } 
  if (f[at][carry] != -1) {
    return f[at][carry]; 
  }
  f[at][carry] = 0;
  for (int i1 : good) {
    for (int i2 : good) {
      for (int i3 : good) {
        for (int i4 : good) {
          for (int i5 : good) {
            for (int i6 : good) {
              int now = i1 + i2 + i3 + i4 + i5 + i6 + carry;
              if (now % 10 != goal[at]) continue;
              f[at][carry] |= call(at + 1, now / 10);
              if (f[at][carry]) {
                ans[0] *= 10, ans[0] += i1;
                ans[1] *= 10, ans[1] += i2;
                ans[2] *= 10, ans[2] += i3;
                ans[3] *= 10, ans[3] += i4;
                ans[4] *= 10, ans[4] += i5;
                ans[5] *= 10, ans[5] += i6;
                return 1;
              }
            }
          }
        }
      }
    }
  }
  return 0;
}

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%lld", &n);
    fin = 0;
    while (n) {
      goal[fin++] = n % 10;
      n /= 10;
    }
    memset(f, -1, sizeof f);
    memset(ans, 0, sizeof ans);
    if (call(0, 0)) {
      for (int i = 0; i < 6; ++i) {
        printf("%lld ", ans[i]);    
      }
      puts("");
    } else {
      puts("-1");
    }
  }
  return 0;
}