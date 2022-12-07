//Autor: Bartomiej Czarkowski
#include <bits/stdc++.h>

using namespace std;

void setIO(string name) {
	//~ ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((name+".in").c_str(), "r", stdin);
	freopen((name+".out").c_str(), "w", stdout);
}

struct node {
	int w, p;
};

const int N = 3e5 + 10;
int n, m, a, com;
int roz[N];
int t[N];
long long sum[N];
vector <int> v[N];
vector <node> st;

void inss(int x, int l, int r, int ll, int rr, int w) {
	if (l > rr || ll > r) {
		return;
	}
	if (ll <= l && r <= rr) {
		st[x].w += w;
		st[x].p += w;
		return;
	}
	inss(x * 2, l, (l + r) / 2, ll, rr, w);
	inss(x * 2 + 1, (l + r) / 2 + 1, r, ll, rr, w);
	st[x].w = min(st[x * 2].w, st[x * 2 + 1].w) + st[x].p;
}

void ins(int x, int w) {
	inss(1, 1, com, 1, x, w);
}

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &t[i]);
		ins(t[i], 1);
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &roz[i]);
		v[i].clear();
		v[i].resize(roz[i] + 1);
		sum[i] = 0;
		for (int j = 1; j <= roz[i]; ++j) {
			scanf("%d", &v[i][j]);
			sum[i] += v[i][j];
		}
		ins((sum[i] + roz[i] - 1) / roz[i], -1);
	}
	for (int i = 1; i <= m; ++i) {
		ins((sum[i] + roz[i] - 1) / roz[i], 1);
		for (int j = 1; j <= roz[i]; ++j) {
			ins((sum[i] - v[i][j] + roz[i] - 2) / (roz[i] - 1), -1);
			printf("%d", st[1].w >= 0);
			ins((sum[i] - v[i][j] + roz[i] - 2) / (roz[i] - 1), 1);
		}
		ins((sum[i] + roz[i] - 1) / roz[i], -1);
	}
	printf("\n");
	for (int i = 1; i <= n; ++i) {
		ins(t[i], -1);
	}
	for (int i = 1; i <= m; ++i) {
		ins((sum[i] + roz[i] - 1) / roz[i], 1);
	}
}

int main() {
	com = 1;
	while (com < 101'000) {
		com <<= 1;
	}
	st.resize(com << 1);
	//~ --com;
	int q=1;
	scanf("%d", &q);
	while(q--) {
		solve();
	}
	return 0;
}