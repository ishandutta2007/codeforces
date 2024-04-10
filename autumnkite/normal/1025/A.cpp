#include <cstdio>
#include <cstring>
int n, b[35], sum;
char a[100005];
int main(){
	scanf("%d%s", &n, a + 1);
	for (register int i = 1; i <= n; ++i) ++b[a[i] - 97];
	for (register int i = 0; i <= 25; ++i) sum += b[i] > 1;
	if (sum || n == 1) printf("Yes"); else printf("No");
}