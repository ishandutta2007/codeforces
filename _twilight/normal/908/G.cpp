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

const int Mod = 1e9 + 7;

template <const int Mod = :: Mod>
class Z {
	public:
		int v;

		Z() : v(0) {	}
		Z(int x) : v(x){	}
		Z(ll x) : v(x % Mod) {	}

		Z operator + (Z b) {
			int x;
			return Z(((x = v + b.v) >= Mod) ? (x - Mod) : (x));
		}
		Z operator - (Z b) {
			int x;
			return Z(((x = v - b.v) < 0) ? (x + Mod) : (x));
		}
		Z operator * (Z b) {
			return Z(v * 1ll * b.v);
		}
		Z operator ~() {
			return inv(v, Mod);
		}
		Z operator - () {
			return Z(0) - *this;
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
};

Z<> qpow(Z<> a, int p) {
	Z<> rt = Z<>(1), pa = a;
	for ( ; p; p >>= 1, pa = pa * pa) {
		if (p & 1) {
			rt = rt * pa;
		}
	}
	return rt;
}

typedef Z<> Zi;

const int N = 705;

int n;
char s[N];
int c[10];
Zi f[N][10];
Zi pw[11][N], sp[N];

int main() {
	scanf("%s", s);
	n = strlen(s);
	reverse(s, s + n);
	for (int i = 1; i < 11; i++) {
		pw[i][0] = 1;
		for (int j = 1; j <= n; j++) {
			pw[i][j] = pw[i][j - 1] * i;
		}
	}
	sp[0] = 0;
	for (int i = 1; i <= n; i++) {
		sp[i] = sp[i - 1] * 10 + 1;
	}
	for (int j = 1; j < 10; j++) {
		f[0][j] = 10 - j;
	}
	for (int i = 1; i <= n + 1; i++) {
		for (int j = 1; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				if (k < j) {
					f[i][j] += f[i - 1][j];
				} else {
					f[i][j] += f[i - 1][j] * 10 + pw[10][i];
				}
			}
//			cerr << f[i][j].v << ' ';
		}
//		cerr << '\n';
	} 
	Zi ans = 0;
	for (int i = n; ~i; i--) {
		for (int j = 0; j < s[i] - '0'; j++) {
			int s = 0;
			for (int k = 9; k; k--) {
				s += c[k] + (j == k);
				ans += (!i ? 0 : f[i - 1][k]) * pw[10][s] + sp[s] * pw[10][i];
//				cerr << ans.v << " " << i << " " << j << " " << k<< '\n';
			}
		}
		c[s[i] - '0']++;
	}
	Zi sum = 0;
	for (int i = 1; i < 10; i++) {
		sum = sum * pw[10][c[i]] + sp[c[i]] * i;
	}
	ans += sum;
	printf("%d\n", ans.v);
	return 0;
}