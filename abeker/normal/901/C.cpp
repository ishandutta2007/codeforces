#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int MAXN = 3e5 + 5;

struct fenwick {
	ll f[MAXN];
	fenwick() {
		memset(f, 0, sizeof f);
	}
	void update(int x, int val) {
		for (x++; x < MAXN; x += x & -x)
			f[x] += val;
	}
	ll get(int x) {
		ll res = 0;
		for (x++; x; x -= x & -x)
			res += f[x];
		return res;
	}
};

int N, M, Q;
vector <int> E[MAXN];
int bio[MAXN];
vector <int> path;
int lft[MAXN];
vector <int> st[MAXN], en[MAXN];
fenwick sum, cnt;
int l[MAXN], r[MAXN];
ll sol[MAXN];

void load() {
	scanf("%d%d", &N, &M);
	while (M--) {
		int a, b;
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
	}
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++)
		scanf("%d%d", l + i, r + i);
}

void dfs(int x, int p) {
	bio[x] = 1;
	path.push_back(x);
	for (auto it : E[x]) {
		if (it == p || bio[it] == 2)
			continue;
		if (bio[it]) {
			int mx = 1, mn = N;
			for (int i = path.size() - 1; i >= 0; i--) {
				mx = max(mx, path[i]);
				mn = min(mn, path[i]);
				if (path[i] == it)
					break;
			}
			lft[mx] = max(lft[mx], mn);
			continue;
		}
		dfs(it, x);
	}
	bio[x] = 2;
	path.pop_back();
}

void solve() {
	for (int i = 1; i <= N; i++)
		if (!bio[i])
			dfs(i, 0);
	
	for (int i = 1; i <= N; i++)
		lft[i] = max(lft[i], lft[i - 1]);
	
	for (int i = 0; i < Q; i++) {
		st[l[i]].push_back(i);
		en[r[i]].push_back(i);
		sol[i] = (ll)(l[i] + r[i]) * (r[i] - l[i] + 1) / 2;
	}
	
	for (int i = 1; i <= N; i++) {
		for (auto it : st[i]) {
			sol[it] += sum.get(N) - sum.get(l[it] - 1);
			sol[it] += (ll)(l[it] - 1) * cnt.get(l[it] - 1);
		}
		sum.update(lft[i], lft[i]);
		cnt.update(lft[i], 1);
		for (auto it : en[i]) {
			sol[it] -= sum.get(N) - sum.get(l[it] - 1);
			sol[it] -= (ll)(l[it] - 1) * cnt.get(l[it] - 1);
		}
	}
	
	for (int i = 0; i < Q; i++)
		printf("%lld\n", sol[i]);
}

int main() {
	load();
	solve();
	return 0;
}