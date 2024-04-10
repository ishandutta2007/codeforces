#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#define maxn 1000005
#define maxm 1000005
using namespace std;
typedef long long ll;
typedef long double ldouble;

int n, m;
string a[maxn];
int val[maxm];
vector<int> from[8];
int f[maxm][8];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  if (n > 3) {
    cout << "-1" << endl;
    return 0;
  }
  if (n == 1) {
    cout << "0" << endl;
    return 0;
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      val[i] += (a[j][i] - '0') * (1 << j);
    }
  }
  memset(f, 0x3f, sizeof(f));
  if (n == 2) {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        if (__builtin_popcount(i ^ j) & 1) {
          from[i].push_back(j);
        }
      }
      f[0][i] = __builtin_popcount(val[0] ^ i);
    }
    for (int i = 1; i < m; i++) {
      for (int S = 0; S < 4; S++) {
        for (auto T : from[S]) {
          f[i][S] = min(f[i][S], f[i - 1][T] + __builtin_popcount(S ^ val[i]));
        }
      }
    }
    cout << *min_element(f[m - 1], f[m - 1] + 4) << endl;
    return 0;
  }
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if ((i & 1) ^ (i >> 1 & 1) ^ (j & 1) ^ (j >> 1 & 1) && 
          (i >> 1 & 1) ^ (i >> 2 & 1) ^ (j >> 1 & 1) ^ (j >> 2 & 1)) {
        from[i].push_back(j);
      }
    }
    f[0][i] = __builtin_popcount(val[0] ^ i);
  }
  for (int i = 1; i < m; i++) {
    for (int S = 0; S < 8; S++) {
      for (auto T : from[S]) {
        f[i][S] = min(f[i][S], f[i - 1][T] + __builtin_popcount(S ^ val[i]));
      }
    }
  }
  cout << *min_element(f[m - 1], f[m - 1] + 8) << endl;
  return 0;
}