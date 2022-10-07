#include <cstdio>
#include <cstring>
int L, n;
char a[100005], b[100005];
bool add(int n, char *s){
	int k = n - 1;
	while (k >= 0 && s[k] == '9') s[k] = '0', --k;
	if (k == -1){
		for (register int i = n; i; --i) s[i] = s[i - 1];
		return s[0] = '1', 1;
	}
	return ++s[k], 0;
}
bool check(){
	for (register int i = 0; i < n; ++i)
		if (b[i % L] != a[i]) return b[i % L] > a[i];
}
int main(){
	scanf("%d%s", &L, a), n = strlen(a);
	if (add(n, a)) ++n;
	if (n % L){
		for (register int i = 0; i < n - n % L + L; ++i)
			if (i % L == 0) putchar('1'); else putchar('0');
		return putchar('\n'), 0;
	}
	if (n == L) return puts(a), 0;
	for (register int i = 0; i < L; ++i) b[i] = a[i];
	if (!check()) add(L, b);
	for (register int i = 0; i < n; ++i) putchar(b[i % L]);
	putchar('\n');
}