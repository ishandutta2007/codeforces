#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const int N = 3e5 + 5;

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
		friend boolean operator < (const Z& a, const Z& b) {
			return a.v < b.v;
		}
};

typedef Z<998244353> Zi;
typedef Z<1000000007> Zn;

#define par pair<Zi, Zn>

const Zi basei = 142857;
const Zn basen = 233;

int T;
int n;
int s[N];
par pb[N], v[N];

int tp;
Zi vali;
Zn valn;
void pop() {
	vali -= pb[tp].first * s[tp];
	valn -= pb[tp].second * s[tp];
	tp--;
}
void push(int x) {
	s[++tp] = x;
	vali += pb[tp].first * s[tp];
	valn += pb[tp].second * s[tp];
}

void solve() {
	scanf("%d", &n);
	v[0] = par(0, 0), tp = 0;
	vali = 0, valn = 0;
	pb[0] = par(1, 1);
	for (int i = 1; i <= n; i++) {
		pb[i].first = pb[i - 1].first * basei;
		pb[i].second = pb[i - 1].second * basen;
	}
	for (int i = 1, x; i <= n; i++) {
		scanf("%d", &x);
		if (tp && s[tp] == x) {
			pop();
		} else {
			push(x);
		}
		v[i] = par(vali, valn);
	}
	sort(v, v + n + 1);
	int cnt = 1;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!(v[i] == v[i - 1])) {
			ans += 1ll * cnt * (cnt - 1);
			cnt = 1;
		} else {
			cnt++;
		}
	}
	ans += 1ll * cnt * (cnt - 1);
	ans >>= 1;
	printf("%lld\n", ans);
}

int main() {
	scanf("%d", &T);
	while (T--) {
		solve();
	}
	return 0;
}