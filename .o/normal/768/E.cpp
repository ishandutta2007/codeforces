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

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

#define debug(format, ...) printf(format, __VA_ARGS__);

int n;

int main() {
  vector<int> g;
  for(int i = 0; g.size() < 100; i++) {
    for(int j = 0; j <= i && g.size() < 100; j++) {
      g.push_back(i);
    }
  }

  int ans = 0;

  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    int s; scanf("%d", &s);
    ans ^= g[s];
  }

  puts(ans ? "NO" : "YES");
  return 0;
}