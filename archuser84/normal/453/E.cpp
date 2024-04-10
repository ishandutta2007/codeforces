///
///   Oh? You're approaching me?
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

#pragma GCC optimize("O3,fast-math,unroll-loops")
#pragma GCC target("avx2,fma")
#define MIN(a, b) ((a)<(b)?(a):(b))
#define DO(t, ans) x=a[i]*t+b[i];b[i]-=x;x=MIN(x,c[i]);ans+=x

const int N = 100010;
const int S = 1024;
double a[N], b[N], c[N];
int t[N], l[N], r[N];
ll ans[N];
int n, q;

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n;
	Loop (i,0,n) {
		ll x, y, z;
		cin >> x >> y >> z;
		a[i] = z;
		b[i] = x;
		c[i] = y;
	}
	cin >> q;
	Loop (i,0,q) {
		cin >> t[i] >> l[i] >> r[i];
		--l[i];
	}
	for (int ls = 0; ls < n; ls += S) {
		for (int jj = 0; jj < q; jj += 2) {
			if (l[jj] <= ls && l[jj+1] <= ls && ls+S <= r[jj] && ls+S <= r[jj+1]) {
				double ans0 = 0, ans1 = 0;
				double t0 = t[jj], t1 = t[jj+1];
				double x;
				Loop (i,ls,ls+S) {
					DO(t0, ans0);
					DO(t1, ans1);
				}
				ans[jj] += ans0;
				ans[jj+1] += ans1;
			} else Loop (j,jj,jj+2) {
				double ans = 0;
				int l = max(ls, ::l[j]);
				int r = min(ls + S, ::r[j]);
				double t = ::t[j];
				double x;
				Loop (i,l,r)
					{DO(t, ans);}
				::ans[j] += ans;
			}
		}
	}
	Loop (i,0,q) {
		cout << ans[i] << '\n';
	}
}