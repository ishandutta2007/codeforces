#include <cstdio>
#include <cstring>
#define N 200005
char a[N], b[N];
int n, m;
int main(){
	scanf("%d%d%s%s", &n, &m, a + 1, b + 1);
	int fr = 1, ed1 = n, ed2 = m;
	while (a[fr] == b[fr] && fr <= n && fr <= m) ++fr;
	while (a[ed1] == b[ed2] && ed1 && ed2) --ed1, --ed2;
	--fr, ++ed1, ++ed2;
	if (ed1 - fr == 2 && a[fr + 1] == '*' && fr < ed2 || ed1 == 1 && ed2 == 1) printf("YES"); else printf("NO");
}