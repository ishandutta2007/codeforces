#include<bits/stdc++.h>
#define ll long long
#define N 200015
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
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
int t, n, cnt[2], fac[N], ifac[N];
char s[N];

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		scanf("%s", s + 1);
		fac[0] = ifac[0] = 1;
		cnt[0] = cnt[1] = 0;
		rep(i, 1, n) fac[i] = (ll) fac[i - 1] * i % mod;
		rep(i, 1, n) ifac[i] = qpow(fac[i], mod - 2);
		int len = 0;
		rep(i, 1, n) {
			len++;
			if(s[i] == '0') cnt[0]++;
			if(s[i] != s[i + 1]){
				if(s[i] == '1') cnt[1] += len / 2;
				len = 0;
			}
		}
		printf("%lld\n", (ll) fac[cnt[0] + cnt[1]] * ifac[cnt[0]] % mod * ifac[cnt[1]] % mod);
	}
	return 0;
}