#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f ^= 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 300005
int T, a, b, n;
char s[N];
bool solve(){
	a = read(), b = read(), scanf("%s", s + 1), n = strlen(s + 1);
	s[++n] = 'X';
	int lst = 0, cnt = 0, flag = 0, Len;
	for (register int i = 1; i <= n; ++i)
		if (s[i] == 'X'){
			int len = i - lst - 1;
			lst = i;
			if (len < b) continue;
			if (len < a) return 0;
			if (len < (b << 1)){ ++cnt; continue; }
			if (flag) return 0;
			flag = 1, Len = len;
		}
	if (!flag) return cnt & 1;
	for (register int i = 0; i <= Len - a; ++i){
		int j = Len - a - i, Cnt = cnt;
		if ((a <= i && i < (b << 1) || i < b) && (a <= j && j < (b << 1) || j < b)){
			Cnt += (i >= a) + (j >= a);
			if (!(Cnt & 1)) return 1;
		}
	}
	return 0;
}
int main(){
	T = read();
	while (T--) if (solve()) puts("YES"); else puts("NO");
}