# include <bits/stdc++.h>
# define ll long long
using namespace std;
const int MAXN = 14;
const int P = 1000000007;
int n, U;
int w[MAXN];
int lg[1 << MAXN], cnt[1 << MAXN];
ll f[1 << MAXN];
ll f1[MAXN][1 << MAXN];
ll pwr(ll x, ll y){
	x %= P;
	y = (y % (P - 1) + (P - 1)) % (P - 1);
	ll ans = 1;
	while (y){
		if (y & 1) ans = ans * x % P;
		x = x * x % P;
		y >>= 1;
	}
	return ans;
}
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", w + i);
	U = (1 << n) - 1;
	for (int i = 0; i < n; i++) lg[1 << i] = i;
	ll ans = 0;
	for (int i = 0; i < n; i++){
		f1[i][0] = 1;
		for (int s = 1; s < (1 << n); s++){
			f1[i][s] = f1[i][s ^ (s & (-s))] * w[i] % P * pwr(w[i] + w[lg[s & (-s)]], -1) % P;
		}
	}
	for (int s = 1; s < (1 << n); s++) cnt[s] = cnt[s ^ (s & (-s))] + 1;
	for (int s = 0; s < (1 << n); s++){
		f[s] = 1;
		for (int s1 = s; s1; s1 = (s1 - 1) & s){
			if (s1 == s) continue;
			ll nw = 1;
			for (int i = 0; i < n; i++){
				if ((s1 >> i) & 1) nw = nw * f1[i][s ^ s1] % P;
			}
			f[s] = (f[s] - f[s1] * nw) % P;
		}
		ll nw = 1;
		for (int i = 0; i < n; i++){
			if ((s >> i) & 1) nw = nw * f1[i][U ^ s] % P;
		}
		ans = (ans + cnt[s] * f[s] % P * nw) % P;
//		printf("f %d %lld %lld %lld\n", s, f[s], nw, ans);
	}
	printf("%lld\n", (ans + P) % P);
	return 0;
}