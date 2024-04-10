#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) { if (x < y) x = y; }

template <typename T>
inline void chkmin(T &x, T y) { if (x > y) x = y; }

inline int read() {
  #define nc getchar()
  int x = 0;
  char c = nc;
  while (c < 48) c = nc;
  while (c > 47) x = (x << 3) + (x << 1) + (c ^ 48), c = nc;
  return x;
  #undef nc
}

typedef long long ll;
const int maxn = 2e5 + 10;
int n;
ll a[maxn];

typedef long long LL;

vector <LL> divisors;

#define ctz __builtin_ctzll

inline LL mul(LL a, LL b, LL mod) {
	return (a * b - (LL)((long double)a / mod * b + 0.5) * mod + mod) % mod;
}

inline LL qp(LL x, LL y, LL mod) {
	LL res = 1;
	for (; y; y >>= 1, x = (LL)mul(x, x, mod)) if (y & 1) res = mul(res, x, mod);
	return res;
}

inline LL gcd(LL a, LL b){
    if(!a) return b;
    if(!b) return a;
    register int t = ctz(a|b) ;
    a >>= ctz(a) ;
    do{
        b >>= ctz(b) ;
        if(a>b){LL t=b;b=a,a=t;}
        b-=a;
    }while(b);
    return a<<t;
}

const int _A[] = {2, 3, 5, 7, 13, 61, 131};

inline bool pd(LL n) {
  if (n == 2 || n == 3) return 1;
  if (n % 2 == 0 || n == 1 || (n % 6 != 1 && n % 6 != 5)) return 0;
	LL tmp = n - 1; int ct = 0;
	while (!(tmp & 1)) tmp >>= 1, ct++;
	rep(i, 0, 6) {
		if (n == _A[i]) return true;
		LL a = qp(_A[i], tmp, n), nxt = a;
		for (int j = 1; j <= ct; j++) {
			nxt = mul(a, a, n);
			if (nxt == 1 && a != 1 && a != n - 1) return false;
			a = nxt;
		}
		if (a != 1) return false;
	}
	return true;
}

inline LL _abs(LL x) {
	return x >= 0 ? x : -x;
}

inline LL _rand() {
  return ((unsigned long long) Rnd()) << 30 | ((unsigned) Rnd());
}

inline LL _rand(LL x, LL c, LL mod) {
	return (mul(x, x, mod) + c) % mod;
}

inline LL Pollard_Rho(LL n) {
	LL s = 0, t = 0, c = _rand() % (n - 1) + 1, val = 1;
	for (int cir = 1; ; cir <<= 1, s = t, val = 1) {
		for (int i = 0; i < cir; i++) {
			t = _rand(t, c, n), val = mul(val, _abs(t - s), n);
			if (i % 127 == 0) {
				LL g = gcd(val, n);
				if (g != 1) return g;
			}
		}
		LL g = gcd(val, n);
		if (g != 1) return g;
	}
}

void Factor(LL n) {
	if (n == 1) return;
	if (pd(n)) return divisors.push_back(n), void();
	LL d = n;
	while (d == n) d = Pollard_Rho(n);
	while (n % d == 0) n /= d;
	Factor(n), Factor(d);
}

set <ll> S;

int res;

void check(ll num) {
  ll cur = 0;
  rep(i, 1, n) {
    ll val = a[i] / num * num;
    if (val) {
      cur += min(val + num - a[i], a[i] - val);
    } else {
      cur += val + num - a[i];
    }
    if (cur > res) return;
  }
  res = cur;
}

inline int abso(int x) {
  return x < 0 ? -x : x;
}

inline int getrnd() {
  int x;
  do {
    x = abso(Rnd());
  } while (x < 0);
  return x;
}

int main() {
  n = read();
  rep(i, 1, n) {
    scanf("%I64d", a + i);
    res += a[i] % 2;
  }
  int T = 505;
  while (T-- > 0 && S.size() < 600) {
    int pos;
    ll val;
    do {
      pos = getrnd() % n + 1;
      val = a[pos] - 1 + (getrnd() % 3);
    } while (val < 2);
		divisors.clear();
    Factor(val);
    for (ll x : divisors) {
      if (x > 50) {
        S.insert(x);
      }
    }
  }
  rep(num, 3, 50) {
    if (pd(num)) check(num);
  }
  for (ll x : S) {
    check(x);
  }
  cout << res;
  return 0;
}