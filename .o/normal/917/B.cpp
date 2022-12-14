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
#include <unordered_map>
#include <unordered_set>
 
using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
 
#define debug(format, ...) printf(format, __VA_ARGS__);

const ll MOD = (ll)1e9 + 7;

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
  modint operator/ (modint x) { return *this * x.inv(); }

  modint& operator+= (const modint x) { return *this = (*this + x); }
  modint& operator-= (const modint x) { return *this = (*this - x); }
  modint& operator*= (const modint x) { return *this = (*this * x); }
  modint& operator/= (const modint x) { return *this = (*this / x); }

  int operator* () { return v; }

  modint inv() {
    modint ret = 1, cur = v;
    int p = MOD - 2;
    while(p > 0) {
      if(p & 1) ret = ret * cur;
      cur = cur * cur;
      p >>= 1;
    }
    return ret;
  }
};

int N, M;
char gph[105][105];
int indeg[105];

queue<int> que;
vector<int> ord;

bool tb['z'+1][105][105];

int main() {
#ifdef IN_MY_COMPUTER
  freopen("b.in", "r", stdin);
#endif

  scanf("%d%d", &N, &M);
  for(int i = 0; i < M; i++) {
    int u, v; char c[2]; scanf("%d%d%s", &u, &v, c);
    gph[u][v] = *c;
    indeg[v] += 1;
  }

  for(int i = 1; i <= N; i++) {
    if(indeg[i] == 0) {
      que.push(i);
    }
  }

  while(!que.empty()) {
    int u = que.front(); que.pop();
    ord.push_back(u);
    for(int v = 1; v <= N; v++) if(gph[u][v]) {
      if(--indeg[v] == 0) que.push(v);
    }
  }

  assert(ord.size() == N);

  reverse(ord.begin(), ord.end());

  vector<pii> vec;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < i; j++) vec.emplace_back(ord[i], ord[j]);
    for(int j = 0; j < i; j++) vec.emplace_back(ord[j], ord[i]);
    vec.emplace_back(ord[i], ord[i]);
  }

  for(pii it : vec) {
    int u = it.first, v = it.second;
    for(char c = 'a'; c <= 'z'; c++) {
      for(int i = 1; i <= N; i++) {
        tb[c][u][v] |= (gph[u][i] >= c && !tb[gph[u][i]][v][i]);
      }
    }
  }

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) putchar(tb['a'][i][j] ? 'A' : 'B');
    puts("");
  }
  return 0;
}