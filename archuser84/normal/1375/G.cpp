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

const int N = 200'010;
vector<int> A[N];
int cnt[2];
int n;

void dfs(int v, int p, int c)
{
	cnt[c]++;
	for (auto u : A[v])
		if (u != p)
			dfs(u, v, 1-c);
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n;
	Loop (i,1,n) {
		int v, u;
		cin >> v >> u;
		--v; --u;
		A[v].push_back(u);
		A[u].push_back(v);
	}
	dfs(0, -1, 0);
	cout << min(cnt[0], cnt[1])-1 << '\n';
}