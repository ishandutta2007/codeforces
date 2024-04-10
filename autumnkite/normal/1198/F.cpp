#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
int read(){
	register int x = 0;
	register char ch = getchar(), f = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 100005
struct node{
	int v, id;
}a[N];
int n, g1, g2, bel[N];
int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}
int main(){
	srand(19260817);
	n = read(), g1 = 0;
	for (register int i = 1; i <= n; ++i)
		a[i].v = read(), a[i].id = i, g1 = gcd(g1, a[i].v);
	if (g1 > 1) return printf("NO\n"), 0;
	for (register int _ = 100; _; --_){
		std :: random_shuffle(a + 1, a + 1 + n);
		g1 = 0, g2 = 0;
		for (register int i = 1; i <= n; ++i){
			int x = gcd(g1, a[i].v);
			if (x != g1) g1 = x, bel[a[i].id] = 1;
			else g2 = gcd(g2, a[i].v), bel[a[i].id] = 2;
		}
		if (g1 == 1 && g2 == 1){
			printf("YES\n");
			for (register int i = 1; i <= n; ++i) printf("%d ", bel[i]);
			return 0;
		}
	}
	printf("NO\n");
}