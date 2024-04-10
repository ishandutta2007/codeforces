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

const int N_ = 55;
int N;

void my_assert(bool chk) {
  if(!chk) {
    puts("NO");
    exit(0);
  }
}

int main() {
  scanf("%d", &N);
  int y = 0;
  for(int i = 1; i <= N; i++) {
    int t; char s[10];
    scanf("%d%s", &t, s);

    if(y == 0) my_assert(*s == 'S');
    else if(y == 20000) my_assert(*s == 'N');

    if(*s == 'S') y += t;
    else if(*s == 'N') y -= t;

    my_assert(0 <= y && y <= 20000);
  }
  my_assert(y == 0);
  puts("YES");
  return 0;
}