#include <cstdio>
#include <cstring>
#define N 200005
char a[N];
int n, k;
int main(){
	scanf("%d%d%s", &n, &k, a + 1);
	int cnt = 0, top = 0;
	for (register int i = 1; i <= n; ++i){
		if (a[i] == '(' && cnt < (k >> 1)) putchar('('), ++cnt, ++top;
		if (a[i] == ')' && top > 0) putchar(')'), --top;
	}
}