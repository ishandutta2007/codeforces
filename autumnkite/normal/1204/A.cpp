#include <cstdio>
#include <cstring>
int n;
char a[105];
bool check(){
	for (register int i = 1; i < n; ++i)
		if (a[i] == '1') return 0;
	return 1;
}
int main(){
	scanf("%s", a);
	n = strlen(a);
	if (check()) --n;
	printf("%d\n", (n + 1) >> 1);
}