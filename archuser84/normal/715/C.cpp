///
///   There's a reason for your defeat, DIO. One simple reason...
///   You pissed me off.
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

const int N = 100'010;
vector<pll> A[N];
bool block[N];
int cnt[N];
ll pw10[N];
ll pw10i[N];
int n, m;

int dfs_cnt_rem(int v, int p)
{
	cnt[v] = 1;
	Loop (i,0,A[v].size()) {
		if (block[A[v][i].first]) {
			swap(A[v][i], A[v].back());
			A[v].pop_back();
			--i;
		} else if (A[v][i].first != p) {
			cnt[v] += dfs_cnt_rem(A[v][i].first, v);
		}
	}
	return cnt[v];
}

int dfs_cent(int v, int p, int cnt)
{
	for (auto [u, _] : A[v]) {
		if (u == p)
			continue;
		if (::cnt[u] > cnt/2)
			return dfs_cent(u, v, cnt);
	}
	return v;
}

void dfs_le(int v, int p, int d, ll cur, vector<pll>& vec)
{
	vec.push_back({d, cur});
	for (auto [u, w] : A[v]) {
		if (u == p)
			continue;
		dfs_le(u, v, d+1, (cur*10+w)%m, vec);
	}
}

void dfs_be(int v, int p, int d, ll cur, vector<ll>& vec)
{
	vec.push_back(cur);
	for (auto [u, w] : A[v]) {
		if (u == p)
			continue;
		dfs_be(u, v, d+1, (cur+pw10[d]*w)%m, vec);
	}
}

ll solve(int v)
{
	dfs_cnt_rem(v, -1);
	v = dfs_cent(v, -1, cnt[v]);
	map<ll, int> mp;
	vector<pll> vec1;
	vector<ll> vec2;
	ll ans = 0;
	Loop (_,0,2) {
		for (auto [u, w] : A[v]) {
			vec1.clear();
			vec2.clear();
			dfs_le(u, v, 1, w, vec1);
			for (auto [d, x] : vec1) {
				ans += mp[(m-x)*pw10i[d] % m];
				ans += _ == 0 && x == 0;
			}
			dfs_be(u, v, 1, w, vec2);
			for (ll x : vec2) {
				mp[x]++;
				ans += _ == 0 && x == 0;
			}
		}
		mp.clear();
		reverse(A[v].begin(), A[v].end());
	}
	block[v] = 1;
	for (auto [u, _] : A[v])
		ans += solve(u);
	return ans;
}

pll egcd(ll x, ll y) {
	if (!y) return {1, 0};
	auto [a, b] = egcd(y, x%y);
	return {b, a - b*(x/y)};
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> m;
	if (m == 1) Kill((ll)n*(n-1));
	pw10i[0] = pw10[0] = 1; ll i10 = egcd(10%m, m).first; i10 = (i10+m) % m;
	assert(10*i10 % m == 1);
	assert(i10 < m);
	Loop (i,1,N) pw10[i] = pw10[i-1]*10 % m;
	Loop (i,1,N) pw10i[i] = pw10i[i-1]*i10 % m;
	Loop (i,0,n-1) {
		int v, u, w;
		cin >> v >> u >> w; w %= m;
		A[v].push_back({u, w});
		A[u].push_back({v, w});
	}
	cout << solve(0) << '\n';
}