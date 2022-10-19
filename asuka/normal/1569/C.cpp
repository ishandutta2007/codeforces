#include<bits/stdc++.h>
#define ll long long
#define N
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
int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (ll) res * a % mod;
		a = (ll) a * a % mod;
		b >>= 1;
	}
	return res;
}
int T, n, a[200015], fac[200015], inv[200015];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &T);
	fac[0] = 1;
	rep(i, 1, 200000) fac[i] = (ll) fac[i - 1] * i % mod;
	rep(i, 1, 200000) inv[i] = qpow(i, mod - 2);
	while(T--) {
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]);
		sort(a + 1, a + n + 1);
		if(a[n] == a[n - 1]) {
			printf("%d\n", fac[n]);
			continue;
		}
		if(a[n] - a[n - 1] >= 2) {
			printf("0\n");
			continue;
		}
		int cnt = 0;
		rep(i, 1, n) if(a[i] == a[n] - 1) cnt++;
		int res = (ll) fac[n] - (ll) fac[n] * inv[cnt + 1] % mod;
		if(res < 0) res += mod;
		printf("%d\n", res);
	}
	return 0;
}