#include <bits/stdc++.h>

using namespace std;
#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)c.size())
#define ten(n) ((int)1e##n)
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

template<typename ...> static inline int getchar_unlocked(void) { return getchar(); }
template<typename ...> static inline void putchar_unlocked(int c) { putchar(c); }
#define mygc(c) (c)=getchar_unlocked()
#define mypc(c) putchar_unlocked(c)
void reader(int& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }
void reader(ll& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }
int reader(char c[]) { int i, s = 0; for (;;) { mygc(i); if (i != ' '&&i != '\n'&&i != '\r'&&i != '\t'&&i != EOF) break; }c[s++] = i; for (;;) { mygc(i); if (i == ' ' || i == '\n' || i == '\r' || i == '\t' || i == EOF) break; c[s++] = i; }c[s] = '\0'; return s; }
int reader(string& c) { int i; for (;;) { mygc(i); if (i != ' '&&i != '\n'&&i != '\r'&&i != '\t'&&i != EOF) break; }c.push_back(i); for (;;) { mygc(i); if (i == ' ' || i == '\n' || i == '\r' || i == '\t' || i == EOF) break; c.push_back(i); }; return sz(c); }
template <class T, class S> void reader(T& x, S& y) { reader(x); reader(y); }
template <class T, class S, class U> void reader(T& x, S& y, U& z) { reader(x); reader(y); reader(z); }
template <class T, class S, class U, class V> void reader(T& x, S& y, U& z, V & w) { reader(x); reader(y); reader(z); reader(w); }
void writer(int x, char c) { int s = 0, m = 0; char f[10]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(ll x, char c) { int s = 0, m = 0; char f[20]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(const char c[]) { int i; for (i = 0; c[i] != '\0'; i++)mypc(c[i]); }
void writer(const string& x, char c) { int i; for (i = 0; x[i] != '\0'; i++)mypc(x[i]); mypc(c); }
void writer(const char x[], char c) { int i; for (i = 0; x[i] != '\0'; i++)mypc(x[i]); mypc(c); }
template<class T> void writerLn(T x) { writer(x, '\n'); }
template<class T, class S> void writerLn(T x, S y) { writer(x, ' '); writer(y, '\n'); }
template<class T, class S, class U> void writerLn(T x, S y, U z) { writer(x, ' '); writer(y, ' '); writer(z, '\n'); }
template<class T> void writerArr(T x[], int n) { if (!n) { mypc('\n'); return; }FOR(i, n - 1)writer(x[i], ' '); writer(x[n - 1], '\n'); }
template<class T> void writerArr(vector<T>& x) { writerArr(x.data(), (int)x.size()); }

template<class T> void chmin(T& a, const T& b) { if (a > b) a = b; }
template<class T> void chmax(T& a, const T& b) { if (a < b) a = b; }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
ll mod_pow(ll a, ll n, ll mod) {
	ll ret = 1;
	ll p = a % mod;
	while (n) {
		if (n & 1) ret = ret * p % mod;
		p = p * p % mod;
		n >>= 1;
	}
	return ret;
}
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }

const int N = ten(7) + 1;
bool prime[N];
vector<int> prs;
void init_prime() {
	memset(prime, 1, sizeof(prime));
	prime[0] = prime[1] = false;
	for (int i = 2; i < sizeof(prime); i++) if (prime[i])
		for (int j = i * 2; j < sizeof(prime); j += i) prime[j] = false;
	for (int i = 2; i < sizeof(prime); i++) if (prime[i]) prs.push_back(i);
}
int factors[N];
void init_factor() {
	for (int i = 2; i < N; i += 2) factors[i] = 2;
	for (int i = 3; i < N; i += 2) factors[i] = i;
	for (int i = 3; i < N; i += 2) if (factors[i] == i)
		for (int j = 3 * i; j < N; j += 2 * i) chmin(factors[j], i);
}

ll cnt1(int n) {
	ll ret = 0;

	static char di[ten(7) + 1];
	memset(di, 0, sizeof(char) * (n+1));
	for (int i = 2; i <= n; i++) {
		int use = 1 - di[i];
		if (use == 0) continue;
		ll val = (n / i) * ll(n / i);
		ret += val * use;
		for (int j = i * 2; j <= n; j += i) {
			di[j] += use;
		}
	}

	int diagonal = n - 1;
	ret = (ret - diagonal) / 2;

	return ret;
}


ll solve(int n) {
	ll a = cnt1(n);

	ll b = 0;
	{
		static ll sm[ten(7) + 10];
		memset(sm, 0, sizeof(ll) * (n + 2));
		for (int i = 2; i <= n; i++) {
			sm[factors[i]]++;
		}
		sm[1] = 1;
		FOR(i, n + 1) sm[i + 1] += sm[i];

		FOR(l, n) {
			if (l <= 1) continue;
			const int rp = n / l;
			if (l >= rp) break;

			ll ccnt = sm[l] - sm[l - 1];
			ll rcnt = sm[rp] - sm[l];

			// printf("l = %d : ok line = (%d, %d]\n", l, l, rp);
			// printf("[%d] = %lld, (%d, %d] = %lld\n", l, ccnt, l, rp, rcnt);

			b += ccnt * rcnt;
		}
		FOR(l, n) {
			if (l <= 1) continue;
			ll ccnt = sm[l] - sm[l - 1];
			ll addd = ccnt * (ccnt - 1) / 2;
			b += addd;
		}

		b -= a;
	}

	ll dall = 0;
	{
		ll pcnt = 0;
		for (int i = n / 2 + 1; i <= n; i++) if (prime[i]) pcnt++;
		pcnt++; // for 1
		dall = (n - pcnt) * (n - pcnt - 1) / 2;
	}

	ll c = dall - a - b;
	// printf("%d : %lld, %lld, %lld\n", n, a, b, c);

	return a + b * 2 + c * 3;
}

ll solve2(int n) {
	n++;
	static int di[1000][1000];
	memset(di,0x1f, sizeof(di));
	FOR(i, n) FOR(j, n) {
		if (i == 0 || j == 0) continue;
		if (gcd(i, j) != 1) {
			di[i][j] = 1;
		}
	}
	FOR(i, n) di[i][i] = 0;
	FOR(k, n) FOR(i, n) FOR(j, n) chmin(di[i][j], di[i][k] + di[k][j]);

	ll ret = 0;
	int ec[4] = {};
	FOR(i, n) for (int j = i + 1; j < n; j++) {
		if (di[i][j] <= 10) {
			ret += di[i][j];
			if (di[i][j] >= 4) {
				cout << "?";
			}
			ec[di[i][j]]++;
			if (di[i][j] == 3) {
				printf("(%d, %d)\n", i, j);
			}
		}
	}
	writerArr(ec, 4);

	return ret;
}

void tst() {
	for (int i = 21; i <= 100; i++) {
		ll cur = solve(i);
		ll c2 = solve2(i);
		if (cur != c2) {
			cout << "?";
		}
		cout << cur << endl;
	}
}

int main() {
	init_prime();
	init_factor();

	// tst();

	int n; reader(n);

	cout << solve(n) << endl;

	return 0;
}