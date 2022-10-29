#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

// missed charactors / ?

template <typename T>
boolean vmin(T& a, T b) {
	return (a > b) ? (a = b, true) : (false);
}
template <typename T>
boolean vmax(T& a, T b) {
	return (a < b) ? (a = b, true) : (false);
}

template <typename T>
T smax(T x) {
	return x;
}
template <typename T, typename ...K>
T smax(T a, const K &...args) {
	return max(a, smax(args...));
}

template <typename T>
T smin(T x) {
	return x;
}
template <typename T, typename ...K>
T smin(T a, const K &...args) {
	return min(a, smin(args...));
}

// debugging lib

#define VN(x) #x
#define Vmsg(x) VN(x) << " = " << (x)
#define printv(x) cerr << VN(x) << " = " << (x);
#define debug(...) fprintf(stderr, __VA_ARGS__);

template <typename A, typename B>
ostream& operator << (ostream& os, const pair<A, B>& z) {
	os << "(" << z.first << ", " << z.second << ')';
	return os;
}
template <typename T>
ostream& operator << (ostream& os, const vector<T>& a) {
	boolean isfirst = true;
	os << "{";
	for (auto z : a) {
		if (!isfirst) {
			os << ", ";
		}
		os << z;
		isfirst = false;
	}
	os << '}';
	return os;
}

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

const int Mod = 998244353;

template <const int Mod = :: Mod>
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

/* const int N = 2000;

int n, d;
Zi f[20][N][4];

int main() {
//	scanf("%d", &n);
	for (int n = 1; n <= 1000; n++) {
		d = 1;
		memset(f, 0, sizeof(f));
		int m = 1;
		while ((m * 2 + 1) <= n)
			d++, m = m * 2 + 1;
		f[d][0][0] = 1;
		f[d][1][1] = 1;
		int q = n - m;
		while (--d) {
			for (int l = 0; l <= q; l++) {
				for (int sl = 0; sl < 2; sl++) {
					Zi x = f[d + 1][l][sl];
					if (!x.v)
						continue;
					int szl = ((sl >> 1) & 1) ^ (sl & 1) ^ 1;
					for (int r = 0; l + r <= q; r++) {
						for (int sr = 1; sr < 4; sr += 2) {
							Zi y = f[d + 1][r][sr];
							int szr = ((sr >> 1) & 1) ^ (sr & 1) ^ 1;
							f[d][l + r][szl | (szr << 1)] += x * y;
						}
					}
				}
			}
		}
		Zi ans = f[1][q][0] + f[1][q][1] + f[1][q][2] + f[1][q][3];
		if (ans.v)
			debug("%d %d\n", n, ans.v);
	}
	return 0;
} */

int n;
boolean ans[2000000];

int main() {
	int cur = 1;
	while (cur <= 1000000) {
		ans[cur] = ans[cur + 1] = true;
		if (cur & 1) {
			cur = cur * 2 + 2;
		} else {
			cur = cur * 2 + 1;
		}
	}
	scanf("%d", &n);
	printf("%d\n", ans[n]);
	return 0;
}