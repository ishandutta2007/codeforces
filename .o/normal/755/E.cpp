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
#include <unordered_set>
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

#define debug(format, ...) printf(format, __VA_ARGS__);

int N, K;

/*
1--2--3--4-5

1-3
1-4
2-4

1-2-3-4
3-1-4-2 (3)

1-3
1-4
1-5
2-1
2-4
2-5


*/
int main() {
  scanf("%d%d", &N, &K);
  try {
    if(N <= 3) throw -1;
    if(K == 2) {
      if(N <= 4) throw -1;
      vector<pii> ans;
      for(int i = 1; i+1 <= N; i++) ans.push_back(pii(i, i+1));
      throw ans;
    }
    if(K == 3) {
      /*
      1 -> 2 -> {3,4,5,..,n-1} -> n
      */
      vector<pii> ans;
      ans.push_back(pii(1,2));
      for(int i = 3; i < N; i++) {
        ans.push_back(pii(2, i));
        ans.push_back(pii(i, N));
      }
      throw ans;
    }
    throw -1;
  }catch(int e) {
    printf("%d\n", e);
  }catch(vector<pii> vec) {
    printf("%lu\n", vec.size());
    for(auto e : vec) printf("%d %d\n", e.first, e.second);
/*
    vector<vector<bool> > adj(N+1, vector<bool>(N+1));
    for(auto e : vec) {
      int u = e.first, v = e.second;
      adj[u][v] = adj[v][u] = true;
    }

    auto diam = [&adj](bool x) {
      int ret = -1;
      for(int a = 1; a <= N; a++) {
        queue<int> que;
        vector<int> dst(N+1, -1);
        que.push(a); dst[a] = 0;
        int step = 0;
        while(!que.empty()) {
          int u = que.front(); que.pop(); step++;
          for(int v = 1; v <= N; v++) if(dst[v] == -1 && adj[u][v] == x) {
            que.push(v);
            dst[v] = dst[u] + 1;
          }
        }
        if(step < N) return -1;
        ret = max(ret, *max_element(dst.begin(), dst.end()));
      }
      return ret;
    };

    printf(" >> %d %d\n", diam(false), diam(true));
    assert(min(diam(false), diam(true)) == K);*/
  }
  return 0;
}