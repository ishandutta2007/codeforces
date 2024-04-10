
#define _CRT_SECURE_NO_WARNINGS

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

const int N_ = 200500;
const int M_ = 200500;
int N, M;
int wh[M_];
vector<int> clauses[N_];
char ans[M_];

int K[N_];

int remaining[N_];
priority_queue<pair<int, int>, vector<pair<int,int> >, greater<pair<int, int> > > que;

int main() {
#ifndef ONLINE_JUDGE
	freopen("571C.in", "r", stdin);
	freopen("571C.out", "w", stdout);
#endif

	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &K[i]);
		remaining[i] = K[i];
		que.push(pii(K[i], i));
		for (int j = 1; j <= K[i]; j++) {
			int v; scanf("%d", &v);
			clauses[i].push_back(v);
			wh[v > 0 ? v : -v] ^= i;
		}
	}

	while (!que.empty()) {
		int u = que.top().second; que.pop();

		bool good = false;
		int cand = -1; char val = 0;
		for (auto x : clauses[u]) {
			if (x < 0 && ans[-x] == '0') good = true;
			if (x > 0 && ans[+x] == '1') good = true;
			if (ans[abs(x)] == 0) cand = abs(x), val = x > 0 ? '1' : '0';
		}
		if (good) continue;
		if (cand == -1) return 0 & puts("NO");

		ans[cand] = val;

		int w = wh[cand] ^ u;
		if (w > 0) que.push(pii(--remaining[w], w));
	}

	for (int i = 1; i <= M; i++) {
		if(ans[i] == 0) ans[i] = '0';
	}

	for (int i = 1; i <= N; i++) {
		bool good = false;
		for (auto x : clauses[i]) {
			if (x < 0 && ans[-x] == '0') good = true;
			if (x > 0 && ans[+x] == '1') good = true;
		}
		if (!good) assert(0);
	}

	puts("YES");
	puts(ans + 1);
	return 0;
}