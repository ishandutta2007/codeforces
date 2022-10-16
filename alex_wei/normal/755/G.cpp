#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int N = 1 << 16;
const int mod = 998244353;
void add(int &x, int y) {x += y, x >= mod && (x -= mod);}
int ksm(int a, int b) {
	int s = 1;
	while(b) {
		if(b & 1) s = 1ll * s * a % mod;
		a = 1ll * a * a % mod, b >>= 1;
	}
	return s;
}
vector <int> ans;
int n, k, rev[N];
void NTT(vector <int> &a, int op) {
	assert(a.size() == N);
	static ull f[N], w[N];
	for(int i = 0; i < N; i++) f[i] = a[rev[i]];
	for(int k = 1; k < N; k <<= 1) {
		int wn = ksm(op ? 3 : (mod + 1) / 3, (mod - 1) / k / 2);
		for(int i = w[0] = 1; i < k; i++) w[i] = w[i - 1] * wn % mod;
		for(int i = 0; i < N; i += k << 1)
			for(int j = 0; j < k; j++) {
				int y = w[j] * f[i | j | k] % mod;
				f[i | j | k] = f[i | j] + mod - y, f[i | j] += y;
			}
	}
	int coef = op ? 1 : ksm(N, mod - 2);
	for(int i = 0; i < N; i++) a[i] = f[i] % mod * coef % mod;
}
vector <int> operator * (vector <int> a, vector <int> b) {
	// cerr << "chk ";
	// for(int i = 0; i < 4; i++) cout << a[i] << " "; cout << "mult ";
	// for(int i = 0; i < 4; i++) cout << b[i] << " "; cout << "is ";
	for(int i = N >> 1; i < N; i++) a[i] = b[i] = 0; // WATCH OUT!
	NTT(a, 1), NTT(b, 1);
	for(int i = 0; i < N; i++) a[i] = 1ll * a[i] * b[i] % mod;
	NTT(a, 0);
	// for(int i = 0; i < 4; i++) cout << a[i] << " "; cout << "\n";
	return a;
	// return NTT(a, 0), a;
}
map <int, vector <int>> mp;
vector <int> solve(int n) {
	vector <int> ans(N, 0);
	if(n == 0) return ans[0] = 1, ans;
	if(n == 1) return ans[0] = ans[1] = 1, ans;
	if(n == 2) return ans[0] = ans[2] = 1, ans[1] = 3, ans;
	if(mp.find(n) != mp.end()) return mp[n];
	int p = n - 2 >> 1;
	vector <int> f = solve(p), g = solve(p + 1), h = g;
	// cerr << "see " << p << endl;
	// for(int i = 0; i < 4; i++) cout << f[i] << " " << g[i] << endl;
	for(int i = 1; i < N; i++) add(h[i], g[i - 1]), add(h[i], f[i - 1]);
	vector <int> r1 = f * (n & 1 ? g : f), r2 = g * (n & 1 ? h : g);
	for(int i = 0; i < N; i++) ans[i] = r2[i], add(ans[i], i ? r1[i - 1] : 0);
	return mp[n] = ans;
}
int main() {
	// freopen("1.in", "r", stdin);
	for(int i = 0; i < N; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << 15);
	cin >> n >> k, ans = solve(n);
	for(int i = 1; i <= k; i++) cout << ans[i] << " ";
	cout << endl;
	return cerr << clock() << endl, 0;
}

/*
2022/4/28
start thinking at ??:??

 f_{i, j}  n = i  j .
 i , .

 n  2 , m = n / 2.
, f_n = f_m * f_m, .
 {m, m + 1} ,  f_{m - 1} * f_{m - 1} * x ^ 1
 f_{m - 1} .
 k log k log n.

, . f_{m - 1}  f_m, .
 T(n) = 2T(n / 2) + O(1).
 T(n) = O(n).
.

, . .
sb : NTT a, f .
 32767 , .

finish debugging at ??:??
*/