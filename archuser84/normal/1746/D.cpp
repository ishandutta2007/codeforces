#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

const int N = 200'010;
int n, k;
vector<int> A[N];
ll s[N];

pll dfs(int v, ll k)
{
	if (A[v].empty())
		return {s[v] * k, s[v]};
	vector<ll> vec;
	ll sum = 0;
	ll base = k/A[v].size();
	ll add = k%A[v].size();
	for (int u : A[v]) {
		auto [x, y] = dfs(u, base);
		sum += x;
		vec.push_back(y);
	}
	sort(vec.rbegin(), vec.rend());
	Loop (i,0,add)
		sum += vec[i];
	sum += s[v] * k;
	return {sum, vec[add] + s[v]};
}

void solve()
{
	cin >> n >> k;
	Loop (i,0,n)
		A[i].clear();
	Loop (i,1,n) {
		int p;
		cin >> p;
		A[p-1].push_back(i);
	}
	Loop (i,0,n)
		cin >> s[i];
	cout << dfs(0, k).first << '\n';
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}