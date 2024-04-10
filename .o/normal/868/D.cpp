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

const int N_ = 105, M_ = 105;
const int L = 16;

int N, M;
bitset<(1<<L)> tb[N_+M_];
int len[N_+M_];
string pref[N_+M_], suff[N_+M_];
char tmp[105];

int main() {
  scanf("%d", &N);
  for(int i = 1; i <= N; i++) {
    scanf("%s", tmp);
    pref[i] = tmp;
    suff[i] = tmp;
    len[i] = strlen(tmp);
    tb[i].set(1);
    for(int a = 0; a < len[i]; a++) {
      int cur = 0;
      for(int b = a; b - a + 1 < L && b < len[i]; b++) {
        cur = (cur << 1) | (tmp[b] - '0');
        tb[i][cur | (1 << (b - a + 1))] = true;
      }
    }
  }

  scanf("%d", &M);
  for(int i = N+1; i <= N+M; i++) {
    int x, y; scanf("%d%d", &x, &y);

    // i <- x + y
    tb[i] = tb[x] | tb[y];
    len[i] = len[x] + len[y];

    pref[i] = pref[x];
    if(len[x] < L) {
      pref[i] += pref[y];
      if(pref[i].length() > L) pref[i] = pref[i].substr(0, L);
    }
    suff[i] = suff[y];
    if(len[y] < L) {
      suff[i] = suff[x] + suff[y];
      if(suff[i].length() > L) suff[i] = suff[i].substr(suff[i].length() - L, L);
    }

    vector<int> ml(1);
    for(int i = 0, j = (int)suff[x].size()-1; j >= 0; i++, j--) {
      ml.push_back(ml.back() | ((suff[x][j] - '0') << i));
    }
    vector<int> mr(1);
    for(int i = 0; i < pref[y].size(); i++) {
      mr.push_back((mr.back() << 1) | (pref[y][i] - '0'));
    }

    for(int a = 1; a < ml.size(); a++) {
      for(int b = 1; a + b < L && b < mr.size(); b++) {
        tb[i].set((1 << (a + b)) | ((ml[a] << b) | mr[b]));
      }
    }

    int ans = 0;
    while(1) {
      bool good = true;
      for(int mask = 0; mask < (1 << ans) && good; mask++) {
        if(!tb[i][(1 << ans) | mask]) good = false;
      }
      if(!good) break;
      ans += 1;
    }
    ans -= 1;

    printf("%d\n", ans);
  }
  return 0;
}