#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <deque>
#include <utility>
#include <bitset>
#include <limits.h>
#include <time.h>
#include <functional>
#include <numeric>
#include <iostream>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MOD = (int)1e9 + 7;

class modint {
  int v;
public:
  modint (): v(0) { }
  modint (ll v): v((v + MOD) % MOD) { }

  bool operator== (modint x) { return v == x.v; }
  bool operator!= (modint x) { return v != x.v; }

  modint operator+ (modint x) { return v + x.v; }
  modint operator- (modint x) { return v - x.v; }
  modint operator* (modint x) { return (ll)v * x.v; }

  modint& operator+= (const modint x) { return *this = (*this + x); }
  modint& operator-= (const modint x) { return *this = (*this - x); }
  modint& operator*= (const modint x) { return *this = (*this * x); }

  int operator* () { return v; }
};

#define debug(format, ...) printf(format, __VA_ARGS__);

int N, C, D;
vector<int> v[2][100500];
int ans = 0;

void solve (vector<int> *p, int m) {
  vector<pii> mx[2];
  mx[0].resize(m+1);
  mx[1].resize(m+1);
  for(int i = 1; i <= m; i++) {
    mx[0][i] = mx[0][i-1];
    mx[1][i] = mx[1][i-1];
    for(int j = 0; j < p[i].size() && j < 2; j++) {
      pii t = pii(p[i][j], i);
      if(mx[0][i] < t) {
        mx[1][i] = mx[0][i];
        mx[0][i] = t;
      }else if(mx[1][i] < t) {
        mx[1][i] = t;
      }
    }
  }

  for(int i = 1; i < m; i++) {
    int a = mx[0][i].first;
    if(mx[0][i].second == 0) continue;
    int t = mx[0][m-i].second == mx[0][i].second;
    if(mx[t][m-i].second == 0) continue;
    int b = mx[t][m-i].first;
    ans = max(ans, a + b);
  }
}

int main() {
  scanf("%d%d%d", &N, &C, &D);
  for(int i = 1; i <= N; i++) {
    int b, p; char t[2];
    scanf("%d%d%s", &b, &p, t);
    v[*t != 'C'][p].push_back(b);
  }

  for(int c = 1; c <= C; c++)
    sort(v[0][c].begin(), v[0][c].end(), greater<int>());
  solve(v[0], C);

  for(int d = 1; d <= D; d++)
    sort(v[1][d].begin(), v[1][d].end(), greater<int>());
  solve(v[1], D);

  {
    int ret0 = 0, ret1 = 0;
    for(int c = 1; c <= C; c++) {
      if(!v[0][c].empty()) ret0 = max(ret0, v[0][c][0]);
    }
    for(int d = 1; d <= D; d++) {
      if(!v[1][d].empty()) ret1 = max(ret1, v[1][d][0]);
    }
    if(ret0 > 0 && ret1 > 0)
      ans = max(ans, ret0 + ret1);
  }

  printf("%d\n", ans);

  return 0;
}