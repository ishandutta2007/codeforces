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

const int Mod = 1e9 + 7;

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

#define piz pair<int, Zi>

piz operator + (piz a, piz b) {
	if (a.first == b.first) {
		return piz(a.first, a.second + b.second);
	} else if (a.first > b.first) {
		return a;
	} 
	return b;
}
piz operator + (piz a, int x) {
	a.first += x;
	return a;
}

const int N = 5005;

int n, m;
int s[N];

typedef class Cow {
	public:
		int h, l, r;

		Cow(int f, int h) : h(h) {
			int t = h;
			for (l = 1; (t -= (f == s[l])) && (++l <= n); );
			for (r = n, t = h; (t -= (f == s[r])) && (--r); );
			cerr << h << " " << l << " " << r << '\n';
		}
} Cow;

vector<Cow> cow[N];

#define for2(_dd) for (int (_dd) = 2; (_dd)--; )

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	for (int i = 1, x, y; i <= m; i++) {
		cin >> x >> y;
		cow[x].emplace_back(x, y);
	}
	piz ans (0, 0);
	for (int l = 0; l <= n; l++) {
		piz F[2], g[2][2][2];
		F[0] = piz(0, 1), F[1] = piz(0, 0);
		for (int f = 1; f <= n; f++) {
			for2 (x) for2 (y) for2 (z)
				g[x][y][z] = piz(0, 0);
			g[0][0][0] = F[0];
			g[1][0][0] = F[1];	
			for (auto& x : cow[f]) {
				boolean flg = x.l == l;
				if (x.l <= l) {
					g[flg][1][1] = g[flg][1][1] + (g[0][0][1] + 1);
					g[1][1][1] = g[1][1][1] + (g[1][0][1] + 1);
				}
				if (x.r > l) {
					g[0][1][1] = g[0][1][1] + (g[0][1][0] + 1);
					g[1][1][1] = g[1][1][1] + (g[1][1][0] + 1);
				}
				if (x.l <= l) {
					g[flg][1][0] = g[flg][1][0] + (g[0][0][0] + 1);
					g[1][1][0] = g[1][1][0] + (g[1][0][0] + 1);
				}
				if (x.r > l) {
					g[0][0][1] = g[0][0][1] + (g[0][0][0] + 1);
					g[1][0][1] = g[1][0][1] + (g[1][0][0] + 1);
				}
			}
			F[0] = F[1] = piz(0, 0);
			for2 (x) for2 (y) for2 (z)
				F[x] = F[x] + g[x][y][z];
		}
		ans = ans + F[l != 0];
	}
	if (ans.first == 0)
		ans.second = 1;
	cout << ans.first << " " << ans.second.v << '\n';
	return 0;
}