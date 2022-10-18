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
		if (x<0) putc('-'), x = -x;
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
	void print_final() {fwrite(wbuf, 1, p3-wbuf, stdout);}
}
const int MAXL = 2e5 + 123;
const int LOG_N = 19;
int n, m, k, bel[MAXL + 5], sum = 0, s[MAXL + 5], sigma = 122;
int buc[MAXL + 5], sa[MAXL + 5], rk[MAXL + 5], seq[MAXL + 5], ht[MAXL + 5];
pii x[MAXL + 5];
void getsa() { // m not n!
	int vmax = sigma, gr = 0;
	for (int i = 1; i <= m; i++) buc[s[i]]++;
	for (int i = 1; i <= vmax; i++) buc[i] += buc[i - 1];
	for (int i = m; i; i--) sa[buc[s[i]]--] = i;
	for (int i = 1; i <= m; i++) {
		if (s[sa[i]] != s[sa[i - 1]]) ++gr;
		rk[sa[i]] = gr;
	}
	vmax = gr;
	for (int k = 1; k <= m; k <<= 1) {
		for (int i = 1; i <= m; i++) {
			if (i + k <= m) x[i] = mp(rk[i], rk[i + k]);
			else x[i] = mp(rk[i], 0);
		}
		memset(buc, 0, sizeof(buc)); gr = 0; int num = 0;
		for (int i = m - k + 1; i <= m; i++) seq[++num] = i;
		for (int i = 1; i <= m; i++) if (sa[i] > k) seq[++num] = sa[i] - k;
		for (int i = 1; i <= m; i++) buc[x[i].fi]++;
		for (int i = 1; i <= vmax; i++) buc[i] += buc[i - 1];
		for (int i = m; i; i--) sa[buc[x[seq[i]].fi]--] = seq[i];
		for (int i = 1; i <= m; i++) {
			if (x[sa[i]] != x[sa[i - 1]]) ++gr;
			rk[sa[i]] = gr;
		}
		vmax = gr; if (vmax == m) break;
	}
}
void getht() {
	int k = 0;
	for (int i = 1; i <= m; i++) {
		if (rk[i] == 1) continue; if (k) k--;
		int j = sa[rk[i] - 1];
		while (i + k <= m && j + k <= m && s[i + k] == s[j + k]) ++k;
		ht[rk[i]] = k;
	}
}
int st[LOG_N + 2][MAXL + 5];
void buildst() {
	for (int i = 1; i <= m; i++) st[0][i] = ht[i];
	for (int i = 1; i <= LOG_N; i++) for (int j = 1; j + (1 << i) - 1 <= m; j++)
		st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
}
int query_st(int l, int r) {
	int k = 31 - __builtin_clz(r - l + 1);
	return min(st[k][l], st[k][r - (1 << k) + 1]);
}
vector<int> ins[MAXL + 5], del[MAXL + 5];
multiset<int> mx;
int num[MAXL + 5], cnt = 0, mxl[MAXL + 5];
ll res[MAXL + 5];
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		static char buf[MAXL + 5]; scanf("%s", buf + 1);
		int len = strlen(buf + 1); sum += len;
		for (int j = 1; j <= len; j++) s[++m] = buf[j], bel[m] = i;
		s[++m] = ++sigma;
		if (k == 1) printf("%lld ", 1ll * len * (len + 1) / 2);
	}
	if (k == 1) return 0;
	getsa(); getht(); buildst();
//	for (int i = 1; i <= m; i++) printf("%d%c", s[i], " \n"[i == m]);
//	for (int i = 1; i <= m; i++) printf("%d%c", sa[i], " \n"[i == m]);
//	for (int i = 1; i <= m; i++) printf("%d%c", ht[i], " \n"[i == m]);
	for (int i = 1, j = 1; i <= sum; i++) {
		while (j <= sum && cnt < k) {
			num[bel[sa[j]]]++;
			cnt += (num[bel[sa[j]]] == 1);
			j++;
		}
		if (cnt == k) {
			int lcp = query_st(i + 1, j - 1);
			ins[i].pb(lcp); del[j].pb(lcp);
		}
		num[bel[sa[i]]]--;
		cnt -= (!num[bel[sa[i]]]);
	}
	mx.insert(0);
	for (int i = 1; i <= sum; i++) {
		for (int x : ins[i]) mx.insert(x);
		for (int x : del[i]) mx.erase(mx.find(x));
		mxl[i] = (*mx.rbegin());
	}
	for (int i = 2; i <= sum; i++) chkmax(mxl[i], min(mxl[i - 1], ht[i]));
	for (int i = 1; i <= sum; i++) res[bel[sa[i]]] += mxl[i];
	for (int i = 1; i <= n; i++) printf("%lld%c", res[i], " \n"[i == n]);
	return 0;
}