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
#include <unordered_map>
#include <unordered_set>
#include <time.h>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int N_ = 100100;

int N, P[N_];
int A[N_];
bool X[N_], Y[N_];

int main() {
#ifndef ONLINE_JUDGE
	freopen("576B.in", "r", stdin);
	freopen("576B.out", "w", stdout);
#endif

	scanf("%d", &N);
	for (int i = 1; i <= N; i++) scanf("%d", P + i);

	for (int u = 1; u <= N; u++) {
		if (P[u] == u) {
			puts("YES");
			for (int v = 1; v <= N; v++) if (u != v) printf("%d %d\n", u, v);
			return 0;
		}
	}

	for (int u = 1; u <= N; u++) {
		if (X[u]) continue;
		int i = u, l = 0;;
		do {
			X[i] = true;
			++l; i = P[i]; 
		} while (i != u);
		if (l % 2 == 1) return puts("NO") & 0;
	}

	memset(X, 0, sizeof X);
	for (int s = 1; s <= N; s++) if(P[P[s]] == s) {
		puts("YES");
		printf("%d %d\n", P[s], s);
		X[s] = X[P[s]] = true;
		for (int u = 1; u <= N; u++) {
			if (X[u]) continue;
			int i = u, l = 0;
			do {
				printf("%d %d\n", i, ~l&1 ? s : P[s]);
				X[i] = true;
				i = P[i]; ++l;
			} while (i != u);
			if (l % 2 == 1) return puts("NO") & 0;
		}
		return 0;
	}puts("NO");
	return 0;
}