#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;

int N, M, Q;
vector <int> larger[MAXN];
int smaller[MAXN];

void load() {
	scanf("%d%d", &N, &M);
	while (M--) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (a < b) {
			larger[a].push_back(b);
			smaller[b]++;
		}
		else {
			larger[b].push_back(a);
			smaller[a]++;
		}
	}
}

inline ll get(int x) {
	return (ll)smaller[x] * larger[x].size();
}

void solve() {
	ll ans = 0;
	for (int i = 1; i <= N; i++)
		ans += get(i);
	printf("%lld\n", ans);
	
	scanf("%d", &Q);
	while (Q--) {
		int v;
		scanf("%d", &v);
		ans -= get(v);
		for (auto it : larger[v]) {
			ans -= get(it);
			larger[it].push_back(v);
			smaller[it]--;
			ans += get(it);
		}
		smaller[v] += larger[v].size();
		larger[v].clear();
		printf("%lld\n", ans);
	}
}

int main() {
	load();
	solve();
	return 0;
}