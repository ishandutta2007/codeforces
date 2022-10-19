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

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))

const int N = 131072;;
const int S = 2048;
vector<pii> Q[N]; int p[N];
int mn[N];
int a[N], ps[N], ps2[N];
int ans[N];
int n, q;

void Do(int l, int r)
{
	Loop(ly,0,r){
		int mn = ::mn[ly];
		int l2 = max(l, ly);
		for (; p[ly] < Q[ly].size() && Q[ly][p[ly]].first < r; ++p[ly]) {
			int r2 = Q[ly][p[ly]].first;
			Loop(i,l2,r2+1){
				mn = min(mn, ps2[i]);
				ps2[i] -= a[i];
			}
			ans[Q[ly][p[ly]].second] = ps[r2] + mn;
			//cout << Q[ly][p[ly]].second << ' ' << mn << ' ' << ly << '\n';
			l2 = r2+1;
		}
		Loop(i,l2,r){
			mn = min(mn, ps2[i]);
			ps2[i] -= a[i];
		}
		::mn[ly] = mn;
	}
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n;
	Loop(i,0,n) cin >> a[i];
	Loop(i,0,n) ps[i] = ps[i-1]+a[i];
	Loop(i,0,n) ps2[i] = a[i]*(i+1) - ps[i];
	cin >> q;
	Loop(i,0,q){
		int x, y;
		cin >> x >> y;
		--x; --y;
		Q[y-x].push_back({y,i});
	}
	Loop(i,0,n) sort(Q[i].begin(), Q[i].end());
	for (int i = 0; i < n; i += S)
		Do(i, min(i+S, n));
	Loop(i,0,q)
		cout << ans[i] << '\n';
}