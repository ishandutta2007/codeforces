# include <bits/stdc++.h>
# define ll long long
# define fst first
# define snd second
using namespace std;
const int MAXN = 1000051;
const int P = 1000000007;
const int L = 20;
const int U = (1 << L) - 1;
int n;
int a[MAXN];
int f[1 << L];
ll pw[MAXN];
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
	pw[0] = 1;
	for (int i = 1; i < MAXN; i++) pw[i] = pw[i - 1] * 2 % P;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%d", a + i);
		f[a[i]]++;
	}
	for (int i = 0; i < L; i++){
		for (int j = 0; j < (1 << L); j++){
			if (!((j >> i) & 1)) f[j] += f[j ^ (1 << i)];
		}
	}
	ll ans = pw[n] - 1;
	for (int i = 1; i < (1 << L); i++){
		ll na = pw[f[i]] - 1;
		if (__builtin_popcount(i) & 1) ans = (ans - na) % P;
		else ans = (ans + na) % P;
	}
	printf("%lld\n", (ans + P) % P);
	return 0;
}