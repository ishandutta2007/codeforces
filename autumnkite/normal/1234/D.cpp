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
char read_char(){
	char ch = getchar();
	while (!isalpha(ch)) ch = getchar();
	return ch;
}
char s[100005];
int n, q;
struct BIT{
	int c[100005];
	void add(int x, int y){
		for (; x <= n; x += x & -x) c[x] += y;
	}
	int query(int l, int r){
		int s = 0;
		for (; r; r -= r & -r) s += c[r];
		for (--l; l; l -= l & -l) s -= c[l];
		return s;
	}
}T[26];
int main(){
	scanf("%s", s + 1), n = strlen(s + 1);
	for (register int i = 1; i <= n; ++i)
		T[s[i] - 'a'].add(i, 1);
	q = read();
	while (q--){
		int opt = read();
		if (opt == 1){
			int x = read();
			char y = read_char();
			T[s[x] - 'a'].add(x, -1), T[y - 'a'].add(x, 1), s[x] = y;
		}
		else{
			int l = read(), r = read(), ans = 0;
			for (register int i = 0; i < 26; ++i)
				if (T[i].query(l, r)) ++ans;
			printf("%d\n", ans);
		}
	}
}