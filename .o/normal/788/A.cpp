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

int N, A[100500];
ll  B[100500];
ll tbs[100500], tbb[100500];
ll ans = (ll)-1e18;

int main() {
  scanf("%d", &N);
  for(int i = 1; i <= N; i++) {
    scanf("%d", &A[i]);
  }
  for(int i = 1; i < N; i++) {
    B[i] = A[i] - A[i+1];
    if(B[i] < 0) B[i] = -B[i];

    if(i % 2 == 0) B[i] = -B[i];
  }

  for(int i = N-1; i >= 1; i--) {
    tbs[i] = min(B[i], tbs[i+1] + B[i]);
    tbb[i] = max(B[i], tbb[i+1] + B[i]);
    if(i % 2 == 0) ans = max(ans, -tbs[i]);
    if(i % 2 == 1) ans = max(ans, tbb[i]);
  }

  printf("%lld\n", ans);
  return 0;
}