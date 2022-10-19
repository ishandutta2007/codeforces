#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;
const int INF = 1e9;

ll K;
int N;
int a[MAXN];

void load() {
	scanf("%d%lld", &N, &K);
	for (int i = 0; i < N; i++)
		scanf("%d", a + i);
}

inline ll func(int x, int b) {
	return 3ll * b * b + b + 1 - a[x] + INF;
}

int get(int x, ll val) {
	if (func(x, 0) > val)
		return 0;
	int lo = 0, hi = a[x] - 1;
	while (lo < hi) {
		int mid = (lo + hi + 1) / 2;
		if (func(x, mid) <= val)
			lo = mid;
		else
			hi = mid - 1;
	}
	return lo + 1;
}

ll at_most(ll val) {
	ll res = 0;
	for (int i = 0; i < N; i++)
		res += get(i, val);
	return res;
}

void solve() {
	ll lo = 0, hi = func(N, INF);
	while (lo < hi) {
		ll mid = (lo + hi) / 2;
		if (at_most(mid) >= K)
			hi = mid;
		else
			lo = mid + 1;
	}
	ll tot = at_most(lo);
	for (int i = 0; i < N; i++) {
		int tmp = get(i, lo);
		if (tot > K && tmp && func(i, tmp - 1) == lo) {
			tmp--;
			tot--;
		}
		printf("%d ", tmp);
	}
	puts("");
}

int main() {
	load();
	solve();
	return 0;
}