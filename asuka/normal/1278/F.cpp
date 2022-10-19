#include<bits/stdc++.h>
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
const int mod = 998244353, N = 5055;
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
int n, m, k, S[N][N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d%d", &n, &m, &k);
	m = inv(m);
	S[0][0] = 1;
	rep(i, 1, k) rep(j, 1, k) S[i][j] = (S[i - 1][j - 1] + (ll) j * S[i - 1][j] % mod) % mod;
	int res = 0;
	rep(j, 0, k) {
		if(n - j + 1 <= 0) continue;
		int o = (ll) qpow(m, j) * S[k][j] % mod;
		rep(i, n - j + 1, n) o = (ll) o * i % mod;
		res = (res + o) % mod;
	}
	printf("%d\n", res);
	return 0;
}