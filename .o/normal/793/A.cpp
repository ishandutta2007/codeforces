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

int N, K; ll ans; int A[100500];

int main() {
  scanf("%d%d", &N, &K);
  for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
  sort(A+1, A+N+1);
  for(int i = 1; i <= N; i++) {
    if((A[i] - A[1]) % K == 0) {
      ans += (A[i] - A[1]) / K;
    }else {
      ans = -1;
      break;
    }
  }
  printf("%lld\n", ans);
  return 0;
}