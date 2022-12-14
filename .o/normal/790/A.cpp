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

int N, K, P[100];

int main() {
  scanf("%d%d", &N, &K);
  for(int i = 1; i <= N; i++) P[i] = i;

  for(int i = 1; i <= N-K+1; i++) {
    char tmp[100];
    scanf("%s", tmp);
    if(*tmp != 'Y') P[i+K-1] = P[i];
  }

  for(int i = 1; i <= N; i++) {
    int x = P[i];
    printf("A%c%c%c", x/26%26+'a', x%26+'a', i+1<=N?' ':'\n');
  }
  return 0;
}