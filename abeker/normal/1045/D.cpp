#include <bits/stdc++.h>
using namespace std;

typedef double lf;

const int MAXN = 1e5 + 5;
const int SQRT = 350;

int N, Q;
vector <int> adj[MAXN], big[MAXN];
lf prob[MAXN], sum[MAXN];
lf ans;

void load() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lf", prob + i);
		prob[i] = 1 - prob[i];
		ans += prob[i];
	}
	for (int i = 1; i < N; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
		ans -= prob[x] * prob[y];
	}
}

void solve() {
	for (int i = 0; i < N; i++)
		for (auto it : adj[i]) {
			if (adj[it].size() > SQRT)
				big[i].push_back(it);
			sum[i] += prob[it];
		}
				
	scanf("%d", &Q);	
	while (Q--) {
		int x;
		lf val;
		scanf("%d%lf", &x, &val);
		val = 1 - val;
		val -= prob[x];
		ans += val;
		if (adj[x].size() > SQRT)	
			ans -= val * sum[x];
		else {
			for (auto it : adj[x])
				ans -= val * prob[it];
			for (auto it : big[x])
				sum[it] += val;
		}
		prob[x] += val;
		printf("%.10lf\n", ans);
	}
}

int main() {
	load();
	solve();
	return 0;
}