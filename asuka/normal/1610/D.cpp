#include<bits/stdc++.h>
#define ll long long
#define N 200015
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
const int mod = 1e9 + 7;
int n, a[N], pd[N], fac[N], ifac[N];
int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (ll) res * a % mod;
		a = (ll) a * a % mod;
		b >>= 1;
	}
	return res;
}
int C(int a, int b) {
	return (ll) fac[a] * ifac[b] % mod * ifac[a - b] % mod;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	pd[0] = fac[0] = ifac[0] = 1;
	rep(i, 1, n) pd[i] = pd[i - 1] * 2 % mod, fac[i] = (ll) fac[i - 1] * i % mod, ifac[i] = qpow(fac[i], mod - 2);
	VI vec;
	rep(i, 1, n) {
		if(a[i] % 2) continue;
		int cnt = 0;
		while(a[i] % 2 == 0) a[i] /= 2, cnt++; 
		vec.pb(cnt);
	}
	int ans = pd[n] - 1;
	sort(all(vec));
	for(int l = 0, r; l < SZ(vec); l = r + 1) {
		r = l;
		while(r + 1 < SZ(vec) && vec[r + 1] == vec[l]) r++;
		for(int _ = 1; _ <= r - l + 1; _ += 2) {
			(ans += mod - ((ll) C(r - l + 1, _) * pd[SZ(vec) - r - 1] % mod)) %= mod;
		}
	}
	printf("%d\n", ans);
	return 0;
}