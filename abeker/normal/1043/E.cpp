#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 3e5 + 5;

int N, M;
int x[MAXN], y[MAXN];
vector <int> hate[MAXN];
pii p[MAXN];
ll ans[MAXN];
ll cumx[MAXN], cumy[MAXN];
bool bio[MAXN];

void load() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d%d", x + i, y + i);
		p[i] = {x[i] - y[i], i};
	}
	while (M--) {
		int u, v;
		scanf("%d%d", &u, &v);
		hate[u].push_back(v);
		hate[v].push_back(u);
	}
}

ll getx(int lo, int hi) {
	return cumx[hi] - cumy[lo - 1];
}

ll gety(int lo, int hi) {
	return cumy[hi] - cumy[lo - 1];
}

void solve() {
	sort(p + 1, p + N + 1);
	
	for (int i = 1; i <= N; i++) {
		cumx[i] = cumx[i - 1] + x[p[i].second];
		cumy[i] = cumy[i - 1] + y[p[i].second];
	}

	for (int i = 1; i <= N; i++) {
		int id = p[i].second;
		int cnt = N - i;
		ll tot = gety(i + 1, N);
		for (auto it : hate[id])
			if (!bio[it]) {
				cnt--;
				tot -= y[it];
			}
		ans[id] += (ll)cnt * x[id] + tot;
		cnt = i - 1;
		tot = getx(1, i - 1);
		for (auto it : hate[id])
			if (bio[it]) {
				cnt--;
				tot -= x[it];
			}
		ans[id] += (ll)cnt * y[id] + tot;
		bio[id] = true;
	}
	
	for (int i = 1; i <= N; i++)
		printf("%lld ", ans[i]);
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}