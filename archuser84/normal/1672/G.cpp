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

const int mod = 998244353;
const int N = 4010;
vector<int> a(N), b(N);
vector<int> aq(N), bq(N);
vector<int> A[2*N];
int n, m;

bool vis[2*N];
pair<array<int,2>, int> dfs(int v)
{
	array<int,2> ans = {};
	int cnt = 0;
	ans[v >= N? b[v-N]: a[v]]++;
	vis[v] = 1;
	cnt += A[v].size();
	for (int u : A[v]) {
		if (!vis[u]) {
			auto [tmp, tmpc] = dfs(u);
			ans[0] += tmp[0];
			ans[1] += tmp[1];
			cnt += tmpc;
		}
	}
	return {ans, cnt};
}

void solve11()
{
	bool flg[2] = {};
	int p2 = 0;
	Loop (ii,0,n+m) {
		int i = ii >= n? ii-n+N: ii;
		if (vis[i])
			continue;
		auto [tmp, cnt] = dfs(i);
		cnt /= 2;
		int sz = tmp[0] + tmp[1];
		if (sz%2 != tmp[0]%2)
			flg[0] = 1;
		if (sz%2 != tmp[1]%2)
			flg[1] = 1;
		p2 += cnt-sz+1;
	}
	//cout << p2 << ' ' << flg[0] << ' ' << flg[1] << '\n';
	ll ans = 2 - flg[0] - flg[1];
	while (p2--) {
		ans = (ans*2)%mod;
	}
	cout << ans << '\n';
}

void solve01()
{
	bool flg[2] = {};
	Loop (i,0,n) {
		//cout << aq[i] << ' ' << a[i] << '\n';
		if (!aq[i])
			flg[a[i]] = 1;
	}
	ll ans = 2 - flg[0] - flg[1];
	Loop (i,0,n) {
		while(--aq[i] > 0)
			ans = (ans*2)%mod;
	}
	//cout << flg[0] << ' ' << flg[1] << '\n';
	cout << ans << '\n';
}

void solve00()
{
	ll ans = 1;
	Loop (i,0,n) {
		while(aq[i]--)
			ans = (ans*2)%mod;
	}
	cout << ans << '\n';
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> m;
	Loop (i,0,n) Loop (j,0,m) {
		char c;
		cin >> c;
		if (c == '?') {
			A[i].push_back(j+N);
			A[j+N].push_back(i);
			aq[i]++; bq[j]++;
		}
		if (c == '1') {
			a[i] ^= 1;
			b[j] ^= 1;
		}
	}
	if (n%2 == 1 && m%2 == 0) {
		swap(n, m);
		swap(a, b);
		swap(aq, bq);
	}
	if (n%2 == 1 && m%2 == 1)
		solve11();
	if (n%2 == 0 && m%2 == 1)
		solve01();
	if (n%2 == 0 && m%2 == 0)
		solve00();
}