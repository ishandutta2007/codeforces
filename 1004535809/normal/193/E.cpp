#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/hash_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
#define fi first
#define se second
#define fill0(a) memset(a, 0, sizeof(a))
#define fill1(a) memset(a, -1, sizeof(a))
#define fillbig(a) memset(a, 63, sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define mt make_tuple
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
template <typename T1, typename T2> void chkmin(T1 &x, T2 y){
	if (x > y) x = y;
}
template <typename T1, typename T2> void chkmax(T1 &x, T2 y){
	if (x < y) x = y;
}
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
namespace fastio {
	#define FILE_SIZE 1 << 23
	char rbuf[FILE_SIZE], *p1 = rbuf, *p2 = rbuf, wbuf[FILE_SIZE], *p3 = wbuf;
	inline char getc() {
		return p1 == p2 && (p2 = (p1 = rbuf) + fread(rbuf, 1, FILE_SIZE, stdin), p1 == p2) ? -1: *p1++;
	}
	inline void putc(char x) {(*p3++ = x);}
	template <typename T> void read(T &x) {
		x = 0; char c = getc(); T neg = 0;
		while (!isdigit(c)) neg |= !(c ^ '-'), c = getc();
		while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getc();
		if (neg) x = (~x) + 1;
	}
	template <typename T> void recursive_print(T x) {
		if (!x) return;
		recursive_print (x / 10);
		putc (x % 10 ^ 48);
	}
	template <typename T> void print(T x) {
		if (!x) putc('0');
		if (x < 0) putc('-'), x = -x;
		recursive_print(x);
	}
	template <typename T> void print(T x,char c) {print(x); putc(c);}
	void readstr(char *s) {
		char c = getc();
		while (c <= 32 || c >= 127) c = getc();
		while (c > 32 && c < 127) s[0] = c, s++, c = getc();
		(*s) = 0;
	}
	void printstr(string s) {
		for (int i = 0; i < s.size(); i++) putc(s[i]);
	}
	void printstr(char *s) {
		int len = strlen(s);
		for (int i = 0; i < len; i++) putc(s[i]);
	}
	void print_final() {fwrite(wbuf, 1, p3 - wbuf, stdout);}
}
ll n, F[1500005], cMOD = 1e6;
ll smul(ll x, ll y) {
	ll res = 0;
	for (; y; y >>= 1, x = (x + x) % cMOD)
		if (y & 1) res = (res + x) % cMOD;
	return res;
}
struct mat {
	ll a[2][2];
	mat() {memset(a, 0, sizeof(a));}
	mat operator * (const mat &rhs) {
		mat res;
		for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) for (int k = 0; k < 2; k++)
			res.a[i][j] = (res.a[i][j] + smul(a[i][k], rhs.a[k][j])) % cMOD;
		return res;
	}
};
ll getfib(ll x) {
	mat v; v.a[0][0] = v.a[0][1] = v.a[1][0] = 1;
	mat pw; for (int i = 0; i < 2; i++) pw.a[i][i] = 1;
	for (; x; x >>= 1, v = v * v) if (x & 1) pw = pw * v;
	return pw.a[0][1];
}
int main() {
	scanf("%lld", &n); F[1] = F[2] = 1;
	for (int i = 3; i <= 1500000; i++) F[i] = (F[i - 1] + F[i - 2]) % cMOD;
	vector<ll> vec; ll cur = 1500000;
	for (int i = 1; i <= 1500000; i++) if (F[i] == n % 1000000)
		vec.pb(i);
	while (cMOD < 1e13) {
		if (vec.empty()) return puts("-1"), 0;
		cMOD *= 10; vector<ll> nw_vec;
		for (ll v : vec) for (int i = 0; i <= 9; i++) if (getfib(i * cur + v) == n % cMOD)
			nw_vec.pb(i * cur + v);
		sort(nw_vec.begin(), nw_vec.end());
		cur *= 10; swap(nw_vec, vec);
	}
	if (vec.empty()) return puts("-1"), 0;
	printf("%lld\n", vec[0]);
	return 0;
}