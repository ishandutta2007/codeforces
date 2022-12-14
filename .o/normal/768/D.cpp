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

int K, Q;
lf tb[10050][1050];
int main() {
  scanf("%d%d", &K, &Q);
  tb[0][0] = 1;
  for(int i = 1; i <= 10000; i++) {
    for(int j = 1; j <= K; j++) {
      tb[i][j] = (tb[i-1][j] * j + tb[i-1][j-1] * (K-j+1)) / K;
    }
  }

  for(int q = 0; q < Q; q++) {
    int p; scanf("%d", &p);
    int ans = 1;
    while(2e3 * tb[ans][K] + 1e-7 < p) {
      ans += 1;
    }
    printf("%d\n", ans);
  }


    return 0;
}