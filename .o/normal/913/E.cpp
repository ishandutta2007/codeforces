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
#include <tuple>
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

bool sc(const string &a, const string &b) {
  return make_pair(a.size(), a) < make_pair(b.size(), b);
};

const int E = 0, T = 1, F = 2;
struct state {
  string e;
  char t;
  int v;
  state(string _e, char _t, int _v): e(_e), t(_t), v(_v) { }
  bool operator< (const state &s) const {
    return sc(s.e, e);
  }
};

priority_queue<state> pq;
string best[256][1<<8];

bool vis(char t, int v) {
  return best[t][v].length() != 0;
}

int N;

int main() {
#ifdef IN_MY_COMPUTER
  freopen("e.in", "r", stdin);
#endif

  pq.emplace("x", 'F', 0xf0);
  pq.emplace("y", 'F', 0xcc);
  pq.emplace("z", 'F', 0xaa);
  while(!pq.empty()) {
    state s = pq.top(); pq.pop();
    if(vis(s.t, s.v)) {
      continue;
    }
    best[s.t][s.v] = s.e;

    switch(s.t) {
      case 'E':
        // E: E|T
        for(int v = 0; v < (1<<8); v++) {
          if(vis('T', v)) pq.emplace(s.e + "|" + best['T'][v], 'E', s.v | v);
        }
        // F: (E)
        pq.emplace("(" + s.e + ")", 'F', s.v);
        break;
      case 'T':
        // E: E|T
        for(int v = 0; v < (1<<8); v++) {
          if(vis('E', v)) pq.emplace(best['E'][v] + "|" + s.e, 'E', v | s.v);
        }
        // T: T&F
        for(int v = 0; v < (1<<8); v++) {
          if(vis('F', v)) pq.emplace(s.e + "&" + best['F'][v], 'T', s.v & v);
        }
        // E: T
        pq.emplace(s.e, 'E', s.v);
        break;
      case 'F':
        // T: T&F
        for(int v = 0; v < (1<<8); v++) {
          if(vis('T', v)) pq.emplace(best['T'][v] + "&" + s.e, 'T', v & s.v);
        }
        // F: !F
        pq.emplace("!" + s.e, 'F', s.v ^ ((1<<8) - 1));
        // T: F
        pq.emplace(s.e, 'T', s.v);
        break;
    }
  }

  scanf("%d", &N);
  while(N--) {
    char tmp[10]; scanf("%s", tmp);
    int v = 0;
    for(int i = 0; i < 8; i++) v |= (tmp[i] - '0') << i;

    vector<string> cand;
    for(char c : "ETF") {
      if(vis(c, v)) cand.push_back(best[c][v]);
    }

    printf("%s\n", min_element(cand.begin(), cand.end(), sc)->c_str());

  }
  return 0;
}