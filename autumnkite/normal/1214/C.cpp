#include <cstdio>
#include <cstring>
int n;
char s[200005];
int main(){
	scanf("%d%s", &n, s + 1);
	int d = 0, flag = 0;
	for (register int i = 1; i <= n; ++i)
		if (s[i] == '(') ++d;
		else if (!d) if (flag) return printf("No\n"), 0; else flag = 1; else --d;
	if (flag) --d;
	if (d) return printf("No\n"), 0;
	printf("Yes\n");
}