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
pii cnt[N];
vector<int> p[N];
int a[N], b[N];

void solve()
{
	int n;
	cin >> n;
	Loop (i,0,n) {
		cnt[i] = {0, i};
		p[i].clear();
	}
	Loop (i,0,n) {
		cin >> a[i]; --a[i];
		p[a[i]].push_back(i);
		cnt[a[i]].first++;
	}
	sort(cnt, cnt+n, greater<pii>());
	vector<int> vec;
	int m = cnt[0].first;
	Loop (i,0,n) {
		while (p[cnt[i].second].size()) {
			vec.push_back(p[cnt[i].second].back());
			p[cnt[i].second].pop_back();
		}
	}
	Loop (i,m,n+m) {
		b[vec[i%n]] = a[vec[i-m]];
	}
	Loop (i,0,n)
		cout << b[i]+1 << ' ';
	cout << '\n';
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) solve();
}