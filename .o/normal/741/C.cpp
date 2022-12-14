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
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		int x, y; scanf("%d%d", &x, &y);
		X[i] = x, Y[i] = y;
		nxt[x] = y; nxt[y] = x;
	}

	for(int i = 1; i <= 2*N; i++) {
		if(!visited[i]) go(i, true);
	}

	for(int i = 1; i <= N; i++)
		printf("%d %d\n", ans[X[i]]?1:2, ans[Y[i]]?1:2);
    return 0;
}