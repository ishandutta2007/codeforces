#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 5;
const int INF = 1e9;

int N, M, S, E, V, Q;
int st[MAXN], el[MAXN];

void load() {
	scanf("%d%d%d%d%d", &N, &M, &S, &E, &V);
	for (int i = 1; i <= S; i++)
		scanf("%d", st + i);
	for (int i = 1; i <= E; i++)
		scanf("%d", el + i);
}

int get_st(int x) {
	return lower_bound(st, st + S + 2, x) - st;
}

int get_el(int x) {
	return lower_bound(el, el + E + 2, x) - el;
}

ll calc(int x1, int x2, int y) {
	if (!y)
		return abs(x1 - x2);
		
	ll res = INF;
	
	int nxt_st = get_st(x1);
	int nxt_el = get_el(x1);
	
	for (int k = 0; k < 2; k++) {
		res = min(res, (ll)abs(x1 - st[nxt_st]) + abs(st[nxt_st] - x2) + y);
		res = min(res, (ll)abs(x1 - el[nxt_el]) + abs(el[nxt_el] - x2) + (y - 1) / V + 1);
		nxt_st--;
		nxt_el--;
	}
	
	return res;
}

void solve() {
	st[0] = el[0] = -INF;
	st[S + 1] = el[E + 1] = INF;
	
	scanf("%d", &Q);
	while (Q--) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		swap(x1, y1);
		swap(x2, y2);
		printf("%lld\n", min(calc(x1, x2, abs(y1 - y2)), calc(x2, x1, abs(y1 - y2))));	
	}
}

int main() {
	load();
	solve();
	return 0;
}