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

const int N_ = 105;

char home[10];

int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", home);
  int x = 0;
  while(n--) {
    char str[100]; scanf("%s", str);
    if(home[0] == str[0] && home[1] == str[1] && home[2] == str[2]) x++;
    if(home[0] == str[5] && home[1] == str[6] && home[2] == str[7]) x--;
  }
  puts(x ? "contest" : "home");
  return 0;
}