#include<bits/stdc++.h>
#define ll long long
#define N 100015
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
const int mod = 998244353;
int t, n, a[N];
vector<pii> f, g;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		f.clear();
		f.pb(mp(1, 0));
		int ans = 0;
		rep(i, 1, n) {
			g.clear();
			int x = a[i] - 1;
			VI num;
			for(int l = 1, r; l <= x; l = r + 1) {
				r = x / (x / l);
				num.pb(l);
			}
			num.pb(a[i]);
			int ptr = 0;
			for(auto u : num) {
				int k = (a[i] + u - 1) / u;
				while(ptr + 1 < SZ(f) && f[ptr + 1].fi <= a[i] / k) ptr++;
				g.pb(mp(u, (f[ptr].se + (ll) i * k % mod) % mod)); 
			}
			swap(f, g);
			per(_, 0, SZ(f) - 1) {
				if(f[_].fi <= a[i]) {
					(ans += f[_].se) %= mod;
					break;
				}
			}
		}
		rep(len, 1, n) {
			int v = (ll) len * (n - len + 1) % mod;
			(ans += mod - v) %= mod;
		}
		printf("%d\n", ans);
	}
	return 0;
}
/*
1
3
1 2 3
*/