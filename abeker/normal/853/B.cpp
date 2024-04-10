#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 1000005;
const ll INF = 1e12;

int N, M, K;
vector <pii> in[MAXN], out[MAXN];
multiset <ll> in_cost[MAXN], out_cost[MAXN];
ll curr;

void load() {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 1; i <= N; i++) {
		in_cost[i].insert(INF);
		out_cost[i].insert(INF);
	}
	while (M--) {
		int day, st, en, cost;
		scanf("%d%d%d%d", &day, &st, &en, &cost);
		if (st)
			out[day].push_back({st, cost});
		else {
			in[day].push_back({en, cost});
			in_cost[en].insert(cost);
		}
	}
}

void add(int day) {
	for (auto it : out[day]) {
		curr -= *out_cost[it.first].begin();
		out_cost[it.first].insert(it.second);
		curr += *out_cost[it.first].begin();
	}
}

void remove(int day) {
	for (auto it : in[day]) {
		curr -= *in_cost[it.first].begin();
		in_cost[it.first].erase(in_cost[it.first].find(it.second));
		curr += *in_cost[it.first].begin();
	}
}

ll solve() {
	for (int i = 1; i <= N; i++) {
		curr += *out_cost[i].begin();
		curr += *in_cost[i].begin();
	}
	
	ll sol = INF;
	for (int i = 0; i < MAXN; i++) {
		remove(i);
		if (i >= K)
			add(i - K);
		sol = min(sol, curr);
	}
	
	if (sol == INF)
		sol = -1;
	return sol;
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}