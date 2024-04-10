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

const int N_ = 1050;

vector<char> S;
char str[N_];

int main() {
  scanf("%s", str);
  int n = strlen(str);
  S.resize(n);
  for(int i = 0; i < n; i++) S[i] = str[i];

  for(char c = 'a'; c <= 'z' && !S.empty(); c++) {
    if(S[0] != c) return 0 & puts("NO");
    S.erase(std::remove(S.begin(), S.end(), c), S.end());
  }

  puts("YES");
    return 0;
}