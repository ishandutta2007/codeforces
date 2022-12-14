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

const int N_ = 200500;
int N, C[N_], D[N_];

int main() {
  scanf("%d", &N);
  ll low = -(ll)1e17, high = (ll)1e17;
  for(int i = 1; i <= N; i++) {
    int c, d; scanf("%d%d", &c, &d);
    if(d == 1) low = max(low, 1900ll);
    else high = min(high, 1899ll);
    if(low > high) return 0 & puts("Impossible");
    if(low > -(ll)1e17) low += c;
    if(high < (ll)1e17) high += c;
  }
  if(high >= (ll)1e17) return 0 & puts("Infinity");
  printf("%lld\n", high);

    return 0;
}