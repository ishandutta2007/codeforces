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

const int N = 3605, hN = 1805;

int h, w, m;
Zi fac[N], _fac[N];
Zi f[3][hN], g[3][hN];
boolean visr[N], visc[N];

void prepare(int n) {
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = fac[i - 1] * i;
	_fac[n] = ~fac[n];
	for (int i = n; i; i--)
		_fac[i - 1] = _fac[i] * i;
}
Zi comb(int n, int m) {
	return (n < m) ? (0) : (fac[n] * _fac[m] * _fac[n - m]);
}

void work(vector<int> seg, Zi (*f)[hN]) {
	int cur = 0;
	int sum = 0;
	f[cur][0] = 1;
	for (auto l : seg) {
		for (int k = 0; k < 3; k++)
			if (k ^ cur)
				memset(f[k], 0, hN << 2);
		sum += l;
		for (int i = 1; i <= l; i++) {
			cur = (cur + 1) % 3;
			memset(f[cur], 0, hN << 2);
			for (int k = 0; k <= (sum >> 1); k++) {
				f[cur][k] += f[(cur + 2) % 3][k];
				if (k) {
					f[cur][k] += f[(cur + 1) % 3][k - 1];
				}
			}
		}	
	}
	if (cur) {
		for (int i = 0; i <= (sum >> 1); i++)
			f[0][i] = f[cur][i];
	}
}

int main() {
	scanf("%d%d%d", &h, &w, &m);
	int x1, y1, x2, y2;
	while (m--) {
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		if (visr[x1] || visr[x2] || visc[y1] || visc[y2]) {
			puts("0");
			return 0;
		}
		visr[x1] = visr[x2] = visc[y1] = visc[y2] = true;
	}
	vector<int> seg;
	for (int i = 1, j; i <= h; i = j) {
		if (visr[i]) {
			j = i + 1;
		} else {
			for (j = i; j <= h && !visr[j]; j++);
			seg.push_back(j - i);
		}
	}
	work(seg, f);
	seg.clear();
	for (int i = 1, j; i <= w; i = j) {
		if (visc[i]) {
			j = i + 1;
		} else {
			for (j = i; j <= w && !visc[j]; j++);
			seg.push_back(j - i);
		}
	}
	work(seg, g);
	prepare(max(h, w));
	int sumr = 0, sumc = 0;
	for (int i = 1; i <= h; i++)
		sumr += !visr[i];
	for (int i = 1; i <= w; i++)
		sumc += !visc[i];
	Zi ans = 0;
	for (int x = 0; 2 * x <= sumr && x <= sumc; x++) {
		for (int y = 0; x + 2 * y <= sumc && 2 * x + y <= sumr; y++) {
			ans += f[0][x] * comb(sumr - 2 * x, y) * g[0][y] * comb(sumc - 2 * y, x) * fac[x] * fac[y];			
		}
	}
	printf("%d\n", ans.v);
	return 0;
}