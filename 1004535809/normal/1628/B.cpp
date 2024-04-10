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
const int MAXN = 1e5;
int n;
string s[MAXN + 5];
void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> s[i];
	for (int i = 1; i <= n; i++) if (s[i].size() == 1) return puts("YES"), void();
	for (int i = 1; i <= n; i++) if (s[i][0] == s[i].back()) return puts("YES"), void();
	map<string, bool> vis2, vis3;
	for (int i = n; i; i--) {
		if (s[i].size() == 2) {
			if (vis2[s[i]]) return puts("YES"), void();
			vis2[string{s[i][1], s[i][0]}] = 1;
		} else {
			if (vis3[s[i]]) return puts("YES"), void();
			vis2[string{s[i][2], s[i][1]}] = 1;
			vis3[string{s[i][2], s[i][1], s[i][0]}] = 1;
		}
	}
	vis2.clear(); vis3.clear();
	for (int i = 1; i <= n; i++) {
		if (s[i].size() == 2) {
			if (vis2[s[i]]) return puts("YES"), void();
			vis2[string{s[i][1], s[i][0]}] = 1;
		} else {
			if (vis3[s[i]]) return puts("YES"), void();
			vis2[string{s[i][1], s[i][0]}] = 1;
			vis3[string{s[i][2], s[i][1], s[i][0]}] = 1;
		}
	}
	puts("NO");
}
int main() {
	int qu; scanf("%d", &qu);
	while (qu--) solve();
	return 0;
}