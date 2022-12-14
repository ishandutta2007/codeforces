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

const int N_ = 305;
const int T_ = 100500;
const int MOD = (int)1e9 + 7;

int N, Q, T;
int A[N_];
int nxt[N_], prv[N_];
int tb[T_];
bool vis[N_];

int main() {
	scanf("%d%d%d", &N, &Q, &T);
	for(int i = 1; i <= N; i++) scanf("%d", A+i);
	for(int q = 1; q <= Q; q++) {
		int b, c; scanf("%d%d", &b, &c);
		nxt[b] = c; prv[c] = b;
	}

	// cycle
	for(int i = 1; i <= N; i++) {
		memset(vis, false, sizeof vis);
		for(int u = i; u > 0; u = nxt[u]) {
			if(vis[u]) return 0 & puts("0");
			vis[u] = true;
		}
	}

	tb[0] = 1;
	for(int i = 1; i <= N; i++) if(!prv[i]) {
		int sum = 0;
		for(int u = i; u > 0; u = nxt[u]) {
			sum += A[u];
			if(nxt[u] > 0) T = max(T - sum, -1);
			for(int t = sum; t <= T; t++) tb[t] = (tb[t] + tb[t - sum]) % MOD;
		}
	}

	if(T < 0) printf("0\n");
	else printf("%d\n", tb[T]);
	return 0;
}