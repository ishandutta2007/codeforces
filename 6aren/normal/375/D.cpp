#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sp ' '
#define debug cout << "666" << endl;
#define f first
#define s second
#define ii pair<long long, long long>

const int N = 100005;

int n, m, c[N], a[N], res[N], block, sta[N], en[N], Time = 0, cnt[N], pass[N];

vector<int> adj[N];

struct Query {
	int l, r, id, val;
} que[N];

void dfs(int u, int p) {
	sta[u] = ++Time;
	a[sta[u]] = c[u];
	for (auto v : adj[u]) {
		if (v == p) continue;
		dfs(v, u);
	}
	en[u] = Time;
}

bool cmp(Query x, Query y) {
	if (x.r / block != y.r / block) {
		return x.r / block < y.r / block;
	}
	return x.l < y.l;
}

void add(int x) {
	cnt[x]++;
	pass[cnt[x]]++;
}

void sub(int x) {
	pass[cnt[x]]--;
	cnt[x]--;
}

signed main() {
	block = sqrt(n) + 1;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", c + i);
	}
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1, 0);
	for (int i = 1; i <= m; i++) {
		int u, k;
		scanf("%d%d", &u, &k);
		que[i].l = sta[u];
		que[i].r = en[u];
		que[i].val = k;
		que[i].id = i;
	}
	sort(que + 1, que + m + 1, cmp);
	int L = 1, R = 0;
	for (int i = 1; i <= m; i++) {
		int l = que[i].l;
		int r = que[i].r;
		int id = que[i].id;
		int k = que[i].val;
		while (L > l) {
			L--;
			add(a[L]);
		}
		while (R < r) {
			R++;
			add(a[R]);
		}
		while (L < l) {
			sub(a[L]);
			L++;
		}
		while (R > r) {
			sub(a[R]);
			R--;
		}
		res[id] = pass[k];
	}
	for (int i = 1; i <= m; i++) {
		printf("%d\n", res[i]);
	}
	return 0;
}