#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define check(i) if((i) >= Mod) (i) -= Mod
using namespace std;
//typedef long long ll;
const int Mod = 998244353;
int qpow(int b, int p){ int ret = 1; while(p){ if(p & 1) ret = 1ll * ret * b % Mod; b = 1ll * b * b % Mod; p >>= 1; } return ret; }

namespace ntt{
	int N, bl;
	int w[1048888];
	void init(int n){
		bl = 0;
		while((1 << bl) < n) bl++;
		N = 1 << bl;
		w[0] = 1, w[1] = qpow(3, (Mod - 1) / N);
		for(int i = 1; i < N; i++)
			w[i + 1] = 1ll * w[i] * w[1] % Mod;
	}
	void dft(int *a, bool idft = 0){
		int to = 0;
		rep(i, N){
			if(i < to)
				swap(a[i], a[to]);
			int k = bl - 1;
			for(; to & (1 << k); k--) to ^= 1 << k;
			to ^= 1 << k;
		}
		for(int len = 1; len <= bl; len++) for(int l = 0; l < N; l += 1 << len) for(int i = l; i < l + (1 << (len - 1)); i++){
//			cout << len << " " << l << " " << i << endl;
			int a0 = a[i], a1 = 1ll * w[(i - l) << (bl - len)] * a[i + (1 << (len - 1))] % Mod;
			a[i] = a0 + a1; check(a[i]);
			a[i + (1 << (len - 1))] = a0 + Mod - a1; check(a[i + (1 << (len - 1))]);
		}
		if(idft){
			int invn = qpow(N, Mod - 2);
			for(int i = 1; i < N - i; i++)
				swap(a[i], a[N - i]);
			rep(i, N)
				a[i] = 1ll * a[i] * invn % Mod;
		}
	}
}

int n;
int fact[1048888], invfact[1048888];
int a[1048888], b[1048888], c[1048888];
int main(){
	ios::sync_with_stdio(false);
	n = 300000;
	fact[0] = 1;
	rep(i, n) fact[i + 1] = 1ll * fact[i] * (i + 1) % Mod;
	invfact[n] = qpow(fact[n], Mod - 2);
	for(int i = n; i >= 1; i--) invfact[i - 1] = 1ll * invfact[i] * i % Mod;
	for(int i = 0; i <= n; i += 4)
		a[i] = 1ll * fact[i / 2] * invfact[i / 4] % Mod * invfact[i / 2] % Mod;
	int p2 = 1;
	for(int i = 0; i <= n; i += 2){
		b[i] = 1ll * invfact[i / 2] * p2 % Mod;
		p2 = 1ll * p2 * ((Mod + 1) / 2) % Mod;
	}
	for(int i = 0; i <= n; i++)
		c[i] = invfact[i];
//	rep(i, 10)
//		cout << i <<": " << a[i] << " " << b[i] << " " << c[i] << endl;
	ntt::init(1048576);
	ntt::dft(b), ntt::dft(c);
	rep(i, ntt::N)
		b[i] = 1ll * b[i] * c[i] % Mod;
	ntt::dft(b, 1);
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		int ans = 0;
		for(int x = 0; x <= n; x += 4)
			ans = (ans + 1ll * fact[n - x / 2] * a[x] % Mod * b[n - x]) % Mod;
		cout << ans << endl;
	}
	return 0;
}