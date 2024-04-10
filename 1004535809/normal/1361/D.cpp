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
const int MAXN = 5e5;
int n, k, tot;
int gcd(int x, int y) {return (!y) ? x : gcd(y, x % y);}
struct point {
	int x, y; double dis;
	point(int _x = 0, int _y = 0) {x = _x; y = _y; dis = sqrt(1ll * x * x + 1ll * y * y);}
} p[MAXN + 5];
map<pii, int> id;
vector<int> vec[MAXN + 5];
bool cmp(int x, int y) {return p[x].dis < p[y].dis;}
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1, x, y; i <= n; i++) {
		scanf("%d%d", &x, &y); p[i] = point(x, y);
		if (!x && !y) vec[++tot].pb(i);
		else {
			int d = gcd(abs(x), abs(y)); x /= d; y /= d;
			if (!id[mp(x, y)]) id[mp(x, y)] = ++tot;
			vec[id[mp(x, y)]].pb(i);
		}
	}
	for (int i = 1; i <= tot; i++) {
		sort(vec[i].begin(), vec[i].end(), cmp);
		reverse(vec[i].begin(), vec[i].end());
	}
	static double sum[MAXN + 5]; int sumcnt = 0;
	for (int i = 1; i <= tot; i++) {
		int lim = min((int)vec[i].size(), k / 2);
		for (int j = 0; j < lim; j++) sum[++sumcnt] = p[vec[i][j]].dis * (k - 1 - (j << 1));
		double ss = 0;
		for (int j = k / 2; j < vec[i].size(); j++) {
			int u = vec[i][(int)(vec[i].size()) - (j - (k / 2)) - 1];
			sum[++sumcnt] = p[u].dis * (k - j - k / 2 - 1) - ss * 2 + p[u].dis * (j - k / 2);
			ss += p[u].dis;
		}
	}
	sort(sum + 1, sum + sumcnt + 1, greater<double>());
	double res = 0;
	for (int i = 1; i <= k; i++) res += sum[i];
	printf("%.10lf\n", res);
	return 0;
}