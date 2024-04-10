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

const int N_ = 200500;

int N;
int nxt[N_];

bool visited[N_], ans[N_];
int X[N_], Y[N_];

void go (int u, bool color) {
	int v = (u % 2 == 0) ? (u - 1) : (u + 1);
	ans[u] =  color; visited[u] = true;
	ans[v] = !color; visited[v] = true;
	if(!visited[nxt[v]]) go(nxt[v], color);
}

int main() {
  int k, a, b; scanf("%d%d%d", &k, &a, &b);
  bool bad = false;
  bad |= (k > b && a%k != 0);
  bad |= (k > a && b%k != 0);
  bad |= (a/k + b/k == 0);
  printf("%d", bad ? -1 : a/k + b/k);
  return 0;
}