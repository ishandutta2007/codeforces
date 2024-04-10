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

const int N_ = 200500, M_ = 200500;

int N, M;

ll L[N_], R[N_];
pli A[M_];

struct candidate {
	ll l, r; int p;
	candidate(ll l = 0, ll r = 0, int p = 0) : l(l), r(r), p(p) { }
	bool operator< (const candidate &c) const { return l < c.l; }
};

candidate X[N_];

priority_queue<pli, vector<pli>, greater<pli> > PQ;
int ans[N_];

int main() {
#ifndef ONLINE_JUDGE
	freopen("555B.in", "r", stdin);
	freopen("555B.out", "w", stdout);
#endif

	scanf("%d%d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%lld%lld", &L[i], &R[i]);
	}
	for (int i = 0; i < N - 1; i++) {
		X[i] = candidate(L[i + 1] - R[i], R[i + 1] - L[i], i);
	}
	for (int i = 0; i < M; i++) {
		ll a; scanf("%lld", &a);
		A[i] = pli(a, i);
	}
	sort(A, A + M);

	// process
	sort(X, X + N - 1);
	for (int i = 0, j = 0; i < M; i++) {
		while (j < N - 1 && X[j].l <= A[i].first) {
			PQ.push(pli(X[j].r, X[j].p));
			++j;
		}

		pli wh = pli(-1, 0);
		while (!PQ.empty()) {
			wh = PQ.top(); PQ.pop();
			if (wh.first >= A[i].first) break;
			wh = pli(-1, 0);
		}

		if (wh.first >= 0) ans[wh.second] = A[i].second + 1;

	}

	for (int i = 0; i < N - 1; i++) if (ans[i] == 0) return 0 & puts("No");
	puts("Yes"); 
	for (int i = 0; i < N - 1; i++) printf("%d ", ans[i]);
	return 0;
}