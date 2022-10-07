#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 0x3f3f3f3f
int n, pos[26];
char a[500005];
int main(){
	scanf("%s", a + 1), n = strlen(a + 1);
	for (register int i = 0; i < 26; ++i) pos[i] = INF;
	for (register int i = 1; i <= n; ++i)
		if (pos[a[i] - 'a'] == INF) pos[a[i] - 'a'] = i;
	for (register int i = 1; i < 26; ++i) pos[i] = std :: min(pos[i - 1], pos[i]);
	for (register int i = 1; i <= n; ++i)
		if (a[i] > 'a' && pos[a[i] - 'a' - 1] < i) puts("Ann");
		else puts("Mike");
}