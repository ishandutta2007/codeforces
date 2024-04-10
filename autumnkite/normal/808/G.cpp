#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
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
	for (; isspace(ch); ch = getchar()) ;
	for (; !isspace(ch); ch = getchar()) s[++n] = ch;
	s[n + 1] = '\0';
	return n;
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
const int N = 100005;
int n, m, fail[N], trans[N][26], f[2][N];
char s[N], t[N];
int main(){
	m = read(t), n = read(s);
	for (register int i = 1; i <= n; ++i){
		if (i == 1) fail[i] = 0;
		else fail[i] = trans[fail[i - 1]][s[i] - 'a'];
		for (register int j = 0; j < 26; ++j)
			if (j == s[i] - 'a') trans[i - 1][j] = i;
			else if (i == 1) trans[i - 1][j] = 0;
			else trans[i - 1][j] = trans[fail[i - 1]][j];
	}
	int u = 0;
	for (register int i = 0; i < n; ++i) f[u][i] = 0;
	for (register int i = m; i; --i){
		u ^= 1;
		for (register int j = 0; j < n; ++j){
			f[u][j] = 0;
			if (t[i] == '?'){
				for (register int k = 0; k < 26; ++k){
					register int p = trans[j][k];
					if (p == n) f[u][j] = std::max(f[u][j], f[!u][fail[n]] + 1);
					else f[u][j] = std::max(f[u][j], f[!u][p]);
				}
			}
			else{
				register int k = t[i] - 'a', p = trans[j][k];
				if (p == n) f[u][j] = std::max(f[u][j], f[!u][fail[n]] + 1);
				else f[u][j] = std::max(f[u][j], f[!u][p]);
			}
		}
	}
	print(f[u][0]);
}