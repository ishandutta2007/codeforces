#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

const int N = 52;
vector<pair<int,int>> A[N];
ll dis[N][N];
int n, m, s;

void dfs(int r, int v, int p, int d)
{
	dis[r][v] = d;
	for (auto [u, w] : A[v]) {
		if (u != p)
			dfs(r, u, v, d+w);
	}
}

ll dp[N][N];

void calc_dp(int v, int k)
{
	vector<ll> vec;
	for (int u = 0; u < n; ++u) {
		if (A[u].size() > 1)
			continue;
		for (int l = 0; l < k; ++l)
			vec.push_back(dp[u][l] + dis[v][u]);
	}
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	dp[v][k] = vec[k-1];
}

int cnt_sub[N];
int sub[N];
int cnt[N];

int cnt_dfs(int v, int p, int s)
{
	int ans = cnt[v];
	sub[v] = s;
	for (auto [u, _] : A[v]) {
		if (u != p)
			ans += cnt_dfs(u, v, s);
	}
	return ans;
}
void cnt_sub_func(int v)
{
	for (int i = 0; i < A[v].size(); ++i) 
		cnt_sub[i] = cnt_dfs(A[v][i].first, v, i);
}

ll calc_ans()
{
	vector<pair<ll,int>> vec;
	for (int u = 0; u < n; ++u) {
		if (A[u].size() > 1)
			continue;
		for (int l = 0; l < m; ++l)
			vec.push_back({dp[u][l] + dis[s][u], u});
	}
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());

	cnt_sub_func(s);
	int rem = m;
	for (auto [x, u] : vec) {
		if (cnt_sub[sub[u]] == 0)
			continue;
		cnt_sub[sub[u]]--;
		rem--;
		if (rem == 0)
			return x;
	}
	return -1;
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n;
	Loop (i,1,n) {
		int v, u, w;
		cin >> v >> u >> w;
		--v; --u;
		A[v].push_back({u,w});
		A[u].push_back({v,w});
	}
	cin >> s; --s;
	cin >> m;
	Loop (i,0,m) {
		int v;
		cin >> v;
		cnt[v-1]++;
	}
	Loop (i,0,n)
		dfs(i, i, -1, 0);
	Loop (k,1,m) {
		Loop (v,0,n) {
			if (A[v].size() > 1)
				continue;
			calc_dp(v, k);
		}
	}
	cout << calc_ans() << '\n';
}