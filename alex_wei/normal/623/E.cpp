#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int N = 1 << 16;
const int mod = 1e9 + 7;
int ksm(int a, int b, int p) {
	int s = 1;
	while(b) {
		if(b & 1) s = 1ll * s * a % p;
		a = 1ll * a * a % p, b >>= 1;
	}
	return s;
}
long long n;
int k, ans, rev[N];
int fc[N], ifc[N];
void NTT(vector <int> &a, int op, int p) {
	static ull f[N], w[N];
	for(int i = 0; i < N; i++) f[i] = a[rev[i]];
	for(int k = 1; k < N; k <<= 1) {
		int wn = ksm(op ? 3 : ksm(3, p - 2, p), (p - 1) / k / 2, p); // mod -> p =.= 
		for(int i = w[0] = 1; i < k; i++) w[i] = w[i - 1] * wn % p;
		for(int i = 0; i < N; i += k << 1)
			for(int j = 0; j < k; j++) {
				int y = w[j] * f[i | j | k] % p;
				f[i |j | k] = f[i | j] + p - y, f[i | j] += y;
			}
	}
	int coef = op ? 1 : ksm(N, p - 2, p);
	for(int i = 0; i < N; i++) a[i] = f[i] % p * coef % p;
}
vector <int> conv(vector <int> a, vector <int> b, int p) {
	NTT(a, 1, p), NTT(b, 1, p);
	for(int i = 0; i < N; i++) a[i] = 1ll * a[i] * b[i] % p;
	return NTT(a, 0, p), a;
}
vector <int> operator * (vector <int> a, vector <int> b) { // add operator
	for(int i = N >> 1; i < N; i++) a[i] = b[i] = 0;
	__int128 p[3] = {998244353, 1004535809, 469762049}, M = p[0] * p[1] * p[2];
	vector <int> res[3];
	for(int i = 0; i < 3; i++) res[i] = conv(a, b, p[i]);
	for(int i = 0; i < N; i++) {
		__int128 v = 0;
		for(int j = 0; j < 3; j++) v += res[j][i] * (M / p[j]) * ksm((M / p[j]) % p[j], p[j] - 2, p[j]);
		a[i] = v % M % mod;
	}
	return a;
}
map <int, vector <int>> mp;
vector <int> solve(int n) {
	vector <int> ans(N, 0);
	if(n == 1) {
		for(int i = 1; i <= k; i++) ans[i] = 1;
		return ans;
	}
	if(mp.find(n) != mp.end()) return mp[n];
	int a = n >> 1, b = n - a, pw = ksm(2, b, mod), coef = 1;
	vector <int> f = solve(a), g = solve(b), h;
	for(int i = 1; i <= k; i++) f[i] = 1ll * f[i] * (coef = 1ll * coef * pw % mod) % mod * ifc[i] % mod;
	for(int i = 1; i <= k; i++) g[i] = 1ll * g[i] * ifc[i] % mod;
	h = f * g;
	// for(int i = 1; i <= k; i++) cout << h[i] << endl;
	for(int i = 1; i <= k; i++) h[i] = 1ll * h[i] * fc[i] % mod;
	return mp[n] = h;
}
int main() {
	// freopen("1.in", "r", stdin);
	for(int i = 0; i < N; i++) rev[i] = (rev[i >> 1] >> 1) | (i & 1) << 15;
	for(int i = fc[0] = 1; i < N; i++) fc[i] = 1ll * fc[i - 1] * i % mod;
	ifc[N - 1] = ksm(fc[N - 1], mod - 2, mod);
	for(int i = N - 2; ~i; i--) ifc[i] = 1ll * ifc[i + 1] * (i + 1) % mod;
	cin >> n >> k;
	if(n > k) puts("0"), exit(0);
	vector <int> res = solve(n);
	for(int i = 1; i <= k; i++) ans = (ans + 1ll * res[i] * fc[k] % mod * ifc[i] % mod * ifc[k - i]) % mod;
	cout << ans << endl;
	return cerr << clock() << endl, 0;
}

/*
2022/4/28
start thinking at 21:26

 CF755G  NTT.
f_{i, j}  n = i,  j  1 .

sb :  k  n!
mod  p .  NTT .
.
 f * g  g  binom(k, j)

=.= 

finish debugging at 23:04
*/