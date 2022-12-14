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

#define debug(format, ...) printf(format, __VA_ARGS__);

int N, M;

vector<pii> solve() {
  vector<pii> ret;

  vector<string> T(N);
  for(int i = 0; i < N; i++) cin >> T[i];

  auto rotate = [&T, &ret](int x, int y) {
    char c;
    if(T[x][y] == 'L') {
      if(T[x][y+1] == 'R' && T[x+1][y] == 'L' && T[x+1][y+1] == 'R')
        c = 'U';
      else
        return false;
    }else if(T[x][y] == 'U') {
      if(T[x][y+1] == 'U' && T[x+1][y] == 'D' && T[x+1][y+1] == 'D')
        c = 'L';
      else
        return false;
    }else {
      return false;
    }

    if(c == 'U') {
      T[x][y] = T[x][y+1] = 'U';
      T[x+1][y] = T[x+1][y+1] = 'D';
    }else {
      T[x][y] = T[x+1][y] = 'L';
      T[x][y+1] = T[x+1][y+1] = 'R';
    }

    ret.push_back(pii(x, y));
    return true;
  };

  std::function<void(int, int)> go = [&] (int x, int y) {
    while(!rotate(x, y)) {
      // LR
      // UL
      while(!rotate(x+1, y)) {
        go(x+1, y+1);
      }
    }
  };

  for(int i = 0; i < N-1; i++) for(int j = 0; j < M; j++) {
    if(T[i][j] == 'L') {
      go(i, j);
    }
  }

  return ret;
}

int main() {
  cin >> N >> M;
  vector<pii> ans1 = solve();
  vector<pii> ans2 = solve();
  reverse(ans2.begin(), ans2.end());

  printf("%ld\n", ans1.size() + ans2.size());
  for(auto p : ans1) printf("%d %d\n", p.first+1, p.second+1);
  for(auto p : ans2) printf("%d %d\n", p.first+1, p.second+1);
  return 0;
}