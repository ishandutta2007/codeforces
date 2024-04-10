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

const int N_ = 100500;
int N, A[N_], P[N_];

int par[N_];
ll sum[N_];

int get (int x) {
	return par[x] == x ? x : (par[x] = get(par[x]));
}

ll ans[N_];
bool good[N_];
ll cur;

void merge (int u, int v) {
	u = get(u);
	v = get(v);
	if(u != v) {
		par[v] = u;
		sum[u] += sum[v];
		cur = max(cur, sum[u]);
		sum[v] = 0;
	}
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}
	for(int i = 1; i <= N; i++) {
		scanf("%d", &P[i]);
		par[i] = i; sum[i] = 0;
	}

	for(int i = N; i > 0; i--) {
		ans[i] = cur;

		int p = P[i];
		good[p] = true;
		sum[p] = A[p];
		cur = max(cur, sum[p]);

		if(p > 1 && good[get(p-1)])
			merge(p-1, p);

		if(p < N && good[get(p+1)])
			merge(p, p+1);
	}

	for(int i = 1; i <= N; i++) 
		printf("%lld\n", ans[i]);

    return 0;
}