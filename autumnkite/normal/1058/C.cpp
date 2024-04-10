#include <cstdio>
int n, m;
char a[105];
int main(){
	scanf("%d%s", &n, a + 1);
	for (register int i = 1; i <= n; ++i) m += a[i] -= 48;
	for (register int s = 1; s < m; ++s){
		int t = 0;
		for (register int i = 1; i <= n; ++i){
			t += a[i];
			if (t == s) t = 0;
			else if (t > s) break;
		}
		if (!t) return printf("YES"), 0;
	}
	if (!m) return printf("YES"), 0;
	printf("NO");
}