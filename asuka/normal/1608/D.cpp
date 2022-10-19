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
const int mod = 998244353, N = 200015;
int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (ll) res * a % mod;
		a = (ll) a * a % mod;
		b >>= 1;
	}
	return res;
}
int n, st[3], ed[3], fac[N], ifac[N];
char s[N][5];
int C(int a, int b) {
	if(a < b || b < 0) return 0;
	return (ll) fac[a] * ifac[b] % mod * ifac[a - b] % mod;
}
int fuck(int ch) {
	if(ch == 'B') return 0;
	if(ch == 'W') return 1;
	return 2;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &n);
	fac[0] = ifac[0] = 1;
	rep(i, 1, n) fac[i] = (ll) fac[i - 1] * i % mod, ifac[i] = qpow(fac[i], mod - 2);
	rep(i, 1, n) {
		scanf("%s", s[i] + 1);
		st[fuck(s[i][1])]++;
		ed[fuck(s[i][2])]++;
		// printf("%d %d\n", fuck(s[1]), fuck(s[2]));
	}
	int ans = 0;
	rep(i, 0, st[2]) {
		int j = (st[0] + i) - ed[1];
		// printf("%d %d %d %d\n", st[2], i, ed[2], j);
		(ans += (ll) C(st[2], i) * C(ed[2], j) % mod) %= mod;
	}
	// BW WB
	int cnt[3] = {0, 0, 0}, flag = 1;
	rep(i, 1, n) {
		if(s[i][1] == s[i][2] && s[i][1] != '?') {
			flag = 0;
			break;
		}
		if(s[i][1] == 'W' || s[i][2] == 'B') {
			cnt[1]++;
		} else if(s[i][1] == 'B' || s[i][2] == 'W') {
			cnt[0]++;
		} else cnt[2]++;
	}
	if(flag) {
		rep(i, 0, cnt[2]) {
			if(cnt[0] + i > 0 && cnt[1] + (cnt[2] - i) > 0) {
				(ans += mod - C(cnt[2], i)) %= mod;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}