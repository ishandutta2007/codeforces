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
	for (; isspace(ch) && ch != EOF; ch = getchar()) ;
	for (; !isspace(ch) && ch != EOF; ch = getchar()) s[++n] = ch;
	return n;
}
const int N = 1000005;
int n, tp;
long long a[N];
int sta[N];
double avg(int l, int r){ return 1.0 * (a[r] - a[l]) / (r - l);}
void solve(){
	n = read();
	for (register int i = 1; i <= n; ++i) a[i] = read() + a[i - 1];
	tp = 0;
	for (register int i = 1; i <= n; ++i){
		while (tp && avg(sta[tp], i) < avg(sta[tp - 1], sta[tp])) --tp;
		sta[++tp] = i;
	}
	for (register int i = 1, j = 1; i <= n; ++i){
		if (i > sta[j]) ++j;
		printf("%.10lf\n", avg(sta[j - 1], sta[j]));
	}
}
int main(){
	int T = 1;
	while (T--) solve();
}