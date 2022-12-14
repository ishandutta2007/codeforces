#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 5e5 + 10;
const int inf = 1e5 + 10;

int a[maxn];
vector<int> t[maxn];
int dp[(1 << 22) + 10];
int h[maxn], sz[maxn];
int Time = 1, st[maxn], ft[maxn], pos[maxn];
int answer = 0;
int ans[maxn];

void add(int x, int H){
	if (H < 0)
		dp[x] = H;
	else
		dp[x] = max(dp[x], H);
}

int ask(int x, int H){
	int ret = dp[x] + H;
	for (int i = 0; i < 22; i++){
		x ^= (1 << i);
		ret = max(ret, dp[x] + H);
		x ^= (1 << i);
	}
	return ret;
}

void dfs(int v, bool heavy = 0){
	if (t[v].empty()){
		if (heavy == 1)
			add(a[v], h[v]);
		return;
	}
	int bc = t[v].back();
	for (auto u : t[v]){
		dfs(u, (u == bc));
		ans[v] = max(ans[v], ans[u]);
	}
	int last = st[v] + 1;
	ans[v] = max(ans[v], ask(a[v], -h[v]));
	add(a[v], h[v]);
	for (int i = st[v] + 1; i <= st[bc]; i++){
		int u = pos[i];
		if (ft[pos[last]] <= st[u]){
			while (last < i){
				int w = pos[last];
				add(a[w], h[w]);
				last ++;
			}
		}
		if (i == st[bc])
			break;
		ans[v] = max(ans[v], ask(a[u], h[u] - 2 * h[v]));
	}
	if (heavy == 0)
		for (int i = st[v]; i < ft[v]; i++){
			add(a[pos[i]], -inf);
		}
}

int cmp(int v, int u){
	return sz[v] < sz[u];
}

void dfs_st(int v){
	pos[Time] = v;
	st[v] = Time ++;
	for (auto u : t[v]){
		h[u] = h[v] + 1;
		dfs_st(u);
	}
	ft[v] = Time;
}

int dfs_sz(int v){
	sz[v] = 1;
	for (auto u : t[v])
		sz[v] += dfs_sz(u);
	sort(t[v].begin(), t[v].end(), cmp);
	return sz[v];
}

int main(){
	ios_base::sync_with_stdio(false);
	memset(dp, -63, sizeof dp);
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++){
		int p;
		char c;
		cin >> p >> c;
		int x = (int)(c - 'a');
		a[i] = (a[p] ^ (1 << x));
		t[p].push_back(i);
	}
	dfs_sz(1);
	dfs_st(1);
	dfs(1);
	for (int i = 1; i <= n; i++)
		cout << ans[i] << " \n"[i == n];
}