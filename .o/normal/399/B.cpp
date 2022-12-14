#include <stdio.h>

int n;
char s[55];
long long res;

int main() {
	scanf("%d%s", &n, s);
	for(int i = 0; i < n; i++) if(s[i] == 'B') res |= 1ll << i;
	printf("%I64d\n", res);
	return 0;
}