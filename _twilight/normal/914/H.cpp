#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 205;

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

int Mod;

typedef class Z {
	public:
		int v;

		Z() : v(0) {	}
		Z(int x) : v(x){	}
		Z(ll x) : v(x % Mod) {	}

		friend Z operator + (const Z& a, const Z& b) {
			return (ll) a.v + b.v;
		}
		friend Z operator - (const Z& a, const Z& b) {
			return (ll) a.v - b.v;
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
} Z;

typedef Z Zi;

int n, d;
Zi comb[N][N];
Zi f[N][N], g[N];

int main(){
	scanf("%d%d%d", &n, &d, &Mod);
	if (Mod == 1) {
		puts("0");
		return 0;
	}
	comb[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		comb[i][0] = comb[i][i] = 1;
		for (int j = 1; j < i; j++) {
			comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
		}
	}

	f[1][0] = 1, g[1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= d; j++) {
			for (int k = 1; k < i; k++) {
				f[i][j] += f[i - k][j - 1] * g[k] * comb[i - 2][k - 1];
			}
			if (j < d)
				g[i] += f[i][j];
		}
	}
	
	Zi ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int x = 0; x <= d; x++) {
			for (int y = 0; x + y <= d; y++) {
				if (y == 1) {
					continue;
				}
				ans += f[i][x] * f[n - i + 1][y];
			}
		}
	}
	ans = ans * n * (n - 1) * 2;
	printf("%d\n", ans.v);
	return 0;
}