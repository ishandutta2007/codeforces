#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 1e6 + 5;

int N;
pii p[MAXN];
vector <int> E[MAXN];
int dad[MAXN], rnk[MAXN];
int sz[MAXN];
bool bio[MAXN];

void load() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &p[i].first);
		p[i].second = i;
	}
	for (int i = 1; i < N; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		E[x].push_back(y);
		E[y].push_back(x);
	}
}

void init() {
	for (int i = 1; i <= N; i++) {
		dad[i] = i;
		sz[i] = 1;
		rnk[i] = 0;
		bio[i] = false;
	}
}

int find(int x) {
	return dad[x] == x ? x : dad[x] = find(dad[x]);
}

void join(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	if (rnk[x] > rnk[y])
		swap(x, y);
	dad[x] = y;
	rnk[y] += rnk[x] == rnk[y];
	sz[y] += sz[x];
}

ll choose(int x) {
	return (ll)x * (x - 1) / 2;
}

ll calc(int x) {
	ll res = 0;
	bio[x] = true;
	for (auto it : E[x]) {
		if (!bio[it])
			continue;
		res -= choose(sz[find(it)]);
		join(x, it);
	}
	res += choose(sz[find(x)]);
	return res;
}

ll solve() {
	sort(p + 1, p + N + 1);
	
	ll sol = 0;
	for (int k = 0; k < 2; k++) {
		init();
		for (int i = 1; i <= N; i++) {
			ll tmp = calc(p[i].second) * p[i].first;
			sol += k ? -tmp : tmp;
		}
		reverse(p + 1, p + N + 1);
	}
	
	return sol;
}

int main() {
	load();
	printf("%lld\n", solve());
	return 0;
}