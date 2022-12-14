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

int main() {
  int N; scanf("%d", &N);
  puts("YES");
  for(int i = 1; i <= N; i++) {
    int x1, y1, x2, y2; scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    printf("%d\n", 1 + 2 * (abs(x1) % 2) + abs(y1) % 2);
  }
  return 0;
}