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
int n, mod, a[N];
int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (ll) res * a % mod;
		a = (ll) a * a % mod;
		b >>= 1;
	}
	return res;
}
int inv(int x) {return qpow(x, mod - 2);}
int b[N];
void check(int x, int d) {
	rep(i, 0, n - 1) b[i + 1] = (x + (ll) i * d % mod) % mod;
	sort(b + 1, b + n + 1);
	rep(i, 1, n) if(a[i] != b[i]) return;
	printf("%d %d\n", x, d);
	exit(0);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d", &mod, &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	int s1 = 0, s2 = 0;
	rep(i, 1, n) (s1 += a[i]) %= mod, (s2 += (ll) a[i] * a[i] % mod) %= mod;
	rep(i, 1, n) {
		int x = a[i], d = (ll) ((ll) 2 * s1 * inv(n) % mod - (ll) 2 * x + (ll) 2 * mod) * inv(n - 1) % mod;
		int us2 = ((ll) n * x % mod * x % mod + (ll) n * (n - 1) % mod * d % mod * x % mod + (ll) d * d % mod * n % mod * (n - 1) % mod * (2 * n - 1) % mod * inv(6) % mod) % mod;
		if(us2 == s2) check(x, d);
	}
	puts("-1");
	return 0;
}