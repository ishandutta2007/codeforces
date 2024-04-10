#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
char buf[1 << 23], *ps = buf, *pt = buf;
#define getchar() (ps == pt && (pt = (ps = buf) + fread(buf, 1, 1 << 23, stdin), ps == pt) ? EOF : *ps++)
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f ^= 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
int read(char *s){
	int n = 0;
	char ch = getchar();
	for (; isspace(ch) && ch != EOF; ch = getchar()) ;
	for (; !isspace(ch) && ch != EOF; ch = getchar()) s[n++] = ch;
	return s[n] = '\0', n;
}
char pbuf[1 << 23], *pp = pbuf;
#define putchar(x) (pp == pbuf + (1 << 23) ? fwrite(pbuf, 1, 1 << 23, stdout), pp = pbuf : 0, *pp++ = x)
struct __IO_flusher{ ~__IO_flusher(){ fwrite(pbuf, 1, pp - pbuf, stdout); } } IO_flusher;
void print(int x, char ch = '\n'){
	if (x == 0) return putchar('0'), putchar(ch), void(0);
	int cnt = 0, num[25];
	for (x < 0 ? putchar('-'), x = -x : 0; x; x /= 10) num[++cnt] = x % 10;
	while (cnt) putchar(num[cnt] ^ '0'), --cnt;
	putchar(ch);
}
void print(const char *s, int n = -1, char ch = '\n'){
	if (n == -1) n = strlen(s);
	for (register int i = 0; i < n; ++i) putchar(s[i]);
	putchar(ch);
}
const int N = 505;
int n, m, k;
struct node{
	int c, l;
	char a[5];
	node(){}
	node(int _c, const char *_a){
		c = _c, l = strlen(_a);
		for (register int i = 0; i < l; ++i) a[i] = _a[i];
	}
};
std::vector<node> f, g;
void solve(int n){
	if (n == 1){
		if (m > 1) f.push_back(node(m - 1, "R")), f.push_back(node(m - 1, "L"));
		return;
	}
	f.push_back(node(1, "D")), solve(n - 1), f.push_back(node(1, "U"));
	if (m > 1) f.push_back(node(m - 1, "RDU")), f.push_back(node(m - 1, "L"));
}
int main(){
	n = read(), m = read(), k = read();
	solve(n);
	for (node v : f){
		if (!k) break;
		if (k >= v.c * v.l) g.push_back(v), k -= v.c * v.l;
		else{
			node t = v;
			t.c = k / v.l;
			if (t.c) g.push_back(t);
			t.c = 1, t.l = k % v.l;
			if (t.l) g.push_back(t);
			k = 0;
		}
	}
	if (k) return print("NO"), 0;
	print("YES");
	print(g.size());
	for (node v : g) print(v.c, ' '), print(v.a, v.l);
}