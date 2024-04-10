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

const int Mod = 998244353;

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
#define pii pair<int, int>

const int N = 2e3 + 5;

int n, _n, x, y;
Zi s1[N][N];
int cnt[N];
vector<int> a, b;
Zi fac[N], _fac[N], ans[N];

Zi comb(int n, int m) {
	return (n < m) ? (0) : (fac[n] * _fac[m] * _fac[n - m]);
}

inline void	init() {
	scanf("%d", &n), _n = n;
	a = move(vector<int>(n));
	b = move(vector<int>(n));
	for (int i = 0; i < n; i++) {
		scanf("%d", a.data() + i);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", b.data() + i);
	}
	fac[0] = 1;
	for (int i = 1; i <= n; i++) {
		fac[i] = fac[i - 1] * i;
	}
	_fac[n] = ~fac[n];
	for (int i = n; i; i--) {
		_fac[i - 1] = _fac[i] * i;
	}
	s1[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		s1[i][0] = 0, s1[i][i] = 1;
		for (int j = 1; j < i; j++) {
			s1[i][j] = s1[i - 1][j - 1] + s1[i - 1][j] * (i - 1);
		}
	}
}

int m;

pii find_pair() {
	int x = -1;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 2) {
			x = i;
			break;
		}
	}
	if (x == -1) {
		return pii(-1, -1);
	}
	pii rt (-1, -1);
	for (int i = 0; i < (signed) a.size(); i++) {
		if (a[i] == x) {
			rt.first = i;
			break;
		}
	}
	for (int i = 0; i < (signed) b.size(); i++) {
		if (b[i] == x) {
			rt.second = i;
			break;
		}
	}
	return rt;
}

inline void solve() {
	pii par;
	for (int i = 0; i < n; i++) {
		if (a[i])
			cnt[a[i]]++;
		if (b[i])
			cnt[b[i]]++;
	}
	while ((par = find_pair()).first >= 0) {
		cnt[a[par.first]] = 0;
		if (par.first == par.second) {
			a.erase(a.begin() + par.first);
			b.erase(b.begin() + par.first);
			m++;
		} else {
			int fi = par.first, sc = par.second;
			a[fi] = a[sc];
			a.erase(a.begin() + sc);
			b.erase(b.begin() + sc);
		}
		_n--;
	}
	for (int i = 0; i < _n; i++) {
		if (a[i] && b[i]) {
			a.erase(a.begin() + i);
			b.erase(b.begin() + i);
			_n--, i--;
		}
	}
	for (int i = 0; i < _n; i++) {
		if (a[i]) {
			x++;
		}
		if (b[i]) {
			y++;
		}
	}
	int _cnt = 0;
	for (int i = 0; i < _n; i++) {
		_cnt += !a[i] && !b[i];
	}
	for (int i = 0; i <= _n; i++) {
		Zi& rt = ans[i + m], tmp;
		for (int j = 0; j <= x && j <= y; j++) {
			tmp = comb(x, j) * comb(y, j) * fac[j] * s1[_n - j][i];
			if (j & 1) {
				rt -= tmp;
			} else {
				rt += tmp;
			}
		}
		rt *= fac[_cnt];
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", ans[n - i].v);
	}
}

int main() {
	init();
	solve();
	return 0;
}