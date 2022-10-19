#include<bits/stdc++.h>
#define int long long
#define ll long long
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
const int N = 200015, mod = 1e9 + 7;
int n, q, a[N], w[N];
struct BIT {
	ll D[N];
	void add(int p, int v) {
		for(; p <= n; p += lowbit(p)) D[p] += v;
	}
	void madd(int p, int v) {
		for(; p <= n; p += lowbit(p)) (D[p] += v) %= mod;
	}
	ll query(int p) {
		ll res = 0;
		for(; p; p -= lowbit(p)) res += D[p];
		return res;
	}
	ll query(int l, int r) {return query(r) - query(l - 1);}
} W, AW, IW;
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lld%lld", &n, &q);
	rep(i, 1, n) scanf("%lld", &a[i]);
	rep(i, 1, n) scanf("%lld", &w[i]);
	rep(i, 1, n) W.add(i, w[i]), AW.madd(i, (ll) a[i] * w[i] % mod), IW.madd(i, (ll) i * w[i] % mod);
	while(q--) {
		int x, y;
		scanf("%lld%lld", &x, &y);
		if(x < 0) {
			x = -x;
			W.add(x, -w[x] + y);
			AW.madd(x, (ll) a[x] * (mod - w[x] + y) % mod);
			IW.madd(x, (ll) x * (mod - w[x] + y) % mod);
			w[x] = y;
		} else {
			int l = x, r = y, ans = l;
			while(l <= r) {
				int mid = (l + r) >> 1;
				if(W.query(x, mid) >= W.query(mid + 1, y)) ans = mid, r = mid - 1;
				else l = mid + 1;
			}
			l = x; r = y;
			// i in [l, ans] (a_ans - ans + i - a_i) * w_i
			ll res = 0;
			(res += ((ll) W.query(l, ans) % mod * (a[ans] - ans) % mod + (IW.query(l, ans) % mod) + (mod - (AW.query(l, ans) % mod))) % mod) %= mod;
			// i in [ans + 1, r] (a_i - a_ans - i + ans)) * w_i
			(res += ((ll) W.query(ans + 1, r) % mod * (ans - a[ans] + mod) % mod + (mod - (IW.query(ans + 1, r) % mod)) + (AW.query(ans + 1, r) % mod)) % mod) %= mod;
			if(res < 0) res = (mod - ( (-res) % mod)) % mod;
			printf("%lld\n", res % mod);
		}
	}
	return 0;
}