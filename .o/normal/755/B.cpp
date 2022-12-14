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

int N, M;
char s[10000];
set<string> A;

int main() {
  scanf("%d%d", &N, &M);
  for(int i = 0; i < N; i++) {
    scanf("%s", s);
    A.insert(s);
  }
  int cnt = 0;
  for(int i = 0; i < M; i++) {
    scanf("%s", s);
    if(A.find(s) != A.end()) cnt += 1;
  }

  if(cnt % 2 == 0) puts(N > M ? "YES" : "NO");
  else puts(N >= M ? "YES" : "NO");
  return 0;
}