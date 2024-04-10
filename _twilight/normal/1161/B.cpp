#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long

void exgcd(int a, int b, int& x, int& y) {
	if (!b) {
		x = 1, y = 0;
	} else {
		exgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
}

int inv(int a, int n) {
	int x, y;
	exgcd(a, n, x, y);
	return (x < 0) ? (x + n) : (x);
}


template <const int Mod>
class Z {
	public:
		int v;

		Z() : v(0) {	}
		Z(int x) : v(x){	}
		Z(ll x) : v(x % Mod) {	}

		friend Z operator + (const Z& a, const Z& b) {
			int x;
			return Z(((x = a.v + b.v) >= Mod) ? (x - Mod) : (x));
		}
		friend Z operator - (const Z& a, const Z& b) {
			int x;
			return Z(((x = a.v - b.v) < 0) ? (x + Mod) : (x));
		}
		friend Z operator * (const Z& a, const Z& b) {
			return Z(a.v * 1ll * b.v);
		}
		friend Z operator ~(const Z& a) {
			return inv(a.v, Mod);
		}
		friend Z operator - (const Z& a) {
			return Z(0) - a;
		}
		Z& operator += (Z b) {
			return *this = *this + b;
		}
		Z& operator -= (Z b) {
			return *this = *this - b;
		}
		Z& operator *= (Z b) {
			return *this = *this * b;
		}
		friend boolean operator == (const Z& a, const Z& b) {
			return a.v == b.v;
		} 
		friend boolean operator != (const Z& a, const Z& b) {
			return a.v != b.v;
		}
};

typedef Z<998244353> Zi;
typedef Z<1000000007> Zn;

const Zi base1 = 233, _base1 = 777;
const Zn base2 = 142857, _base2 = 233333;

const int N = 1e5 + 5;

int n, m;
Zi hi[N], si[N], pw1[N];
Zn hn[N], sn[N], pw2[N];
int f[N];
vector<int> G[N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1, u, v; i <= m; i++) {
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		for (auto& p : G[i])
			(p < i) && (p += n);
		G[i].push_back(i);
		sort(G[i].begin(), G[i].end());
		for (int j = 1; j < (signed) G[i].size(); j++) {
			hi[i] = hi[i] * base1 + (G[i][j] - G[i][j - 1]);
			hn[i] = hn[i] * base2 + (G[i][j] - G[i][j - 1]);
		}
	}
	pw1[0] = 1, pw2[0] = 1;
	for (int i = 1; i <= n; i++) {
		pw1[i] = pw1[i - 1] * _base1;
		pw2[i] = pw2[i - 1] * _base2;
	}
	for (int i = 1; i <= n; i++) {
		si[i] = si[i - 1] * _base1 + hi[i];
		sn[i] = sn[i - 1] * _base2 + hn[i];
	}
	for (int i = 1; i < n; i++) {
		Zi a = (si[n] - si[i] * pw1[n - i]) * pw1[i] + si[i];
		Zn b = (sn[n] - sn[i] * pw2[n - i]) * pw2[i] + sn[i];
		if (a == si[n] && b == sn[n]) {
			puts("Yes");
			return 0;
		}
	}
	puts("No");
	return 0;
}