#include <cstdio>
#include <cstring>
#define N 300005
int n, len[N];
char a[N];
long long ans;
int main(){
	scanf("%d%s", &n, a + 1);
	int lst = 1;
	for (register int i = 2; i <= n; ++i)
		if (a[i] != a[i - 1]){
			for (register int j = lst; j < i; ++j) len[j] = i - lst;
			lst = i;
		}
	for (register int i = lst; i <= n; ++i) len[i] = n - lst + 1;
	for (register int i = 1; i < n; ++i)
		if (i >= lst) ans += n - i;
		else if (a[i] == a[i + 1]) ans += n - i - 1;
		else ans += n - i - len[i + 1];
	printf("%lld\n", ans);
}