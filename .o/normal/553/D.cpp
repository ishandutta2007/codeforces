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

const int N_ = 100500;

int N, M, K;
bool fortress[N_];
vector<int> gph[N_];

int dg[N_], dgf[N_];

struct candidate {
	lf rate;
	int u;

	candidate(int u = 0, lf rate = 0) : u(u), rate(rate) { }
	bool operator<(const candidate &c) const { return rate < c.rate; }
};

priority_queue<candidate> PQ;
bool used[N_];
vector<int> ord;
candidate ans;

int main() {

	scanf("%d%d%d", &N, &M, &K);
	for (int i = 1; i <= K; i++) {
		int u; scanf("%d", &u);
		fortress[u] = true;
	}
	for (int e = 0; e < M; e++) {
		int u, v; scanf("%d%d", &u, &v);
		gph[u].push_back(v); ++dg[u];
		gph[v].push_back(u); ++dg[v];
		if (fortress[u]) ++dgf[v];
		if (fortress[v]) ++dgf[u];
	}

	for (int u = 1; u <= N; u++) {
		if (fortress[u]) continue;
		PQ.push(candidate(u, (lf)dgf[u] / dg[u]));
	}

	used[0] = true;
	ans = candidate(-1, 1000);

	while (!PQ.empty()) {
		candidate c;
		while (!PQ.empty() && used[c.u]) {
			c = PQ.top(); PQ.pop();
		}
		
		if (used[c.u]) continue;

		if (ans.rate > c.rate) ans = c;
		
		int u = c.u;
		used[u] = true;
		ord.push_back(u);
		for (auto v : gph[u]) {
			if (fortress[v] || used[v]) continue;
			++dgf[v];
			PQ.push(candidate(v, (lf)dgf[v] / dg[v]));
		}
	}

	for (int i = 0; i < ord.size(); i++) {
		if (ord[i] == ans.u) {
			ord.erase(ord.begin(), ord.begin() + i);
			break;
		}
	}

	printf("%u\n", ord.size());
	for (auto u : ord) printf("%d ", u);

	return 0;
}