#include<bits/stdc++.h>
#define ll long long
#define N 1000015
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
const int mod = 1e9 + 7, i2 = 500000004, i4 = 250000002;
int n, cnt[N], coef[N], fac[N];
int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &n);
	rep(i, 1, n) {
		int x;
		scanf("%d", &x);
		cnt[x]++;
		(coef[x] += (ll) x * x % mod) %= mod;
	}
	fac[0] = 1;
	rep(i, 1, 1000000) fac[i] = (ll) fac[i - 1] * i % mod;
	int tot = 1, ans = 0;
	per(i, 1, 1000000) {
		tot = (ll) tot * fac[cnt[i]] % mod;
		if(i > 1) tot = (ll) tot * fac[cnt[i]] % mod;
		if(i >= 2) {
			if(i == 2) (ans += (ll) i4 * (coef[i] - (ll) cnt[i] * (i - 2) % mod * (i - 2) % mod + mod) % mod * (cnt[i] + cnt[i - 1]) % mod) %= mod;
			else (ans += (ll) i4 * (coef[i] - (ll) cnt[i] * (i - 2) % mod * (i - 2) % mod + mod) % mod * (cnt[i] + cnt[i - 1] + cnt[i] + cnt[i - 1] + cnt[i - 2]) % mod) %= mod;
			cnt[i - 2] += cnt[i];
			(coef[i - 2] += coef[i]) %= mod;
		}
	}
	printf("%d %d\n", ans, tot);
	return 0;
}
/*

c[u] = i
 j, i (i + j % 2 == 0)  k = ((i - j / 2) + 1)
k * (i - k) = 1 / 4 * (i - j + 2) * (i + j - 2)
= 1 / 4 * (i ^ 2 - (j - 2) ^ 2)
= 1 / 4 * (coef[j] - cnt[j] * (j - 2) ^ 2)
*/