#include <cstdio>
#include <cstring>
#define N 200005
int T, n, sum[N], ans;
char s[N];
int main(){
	scanf("%d", &T);
	while (T--){
		scanf("%s", s + 1), n = strlen(s + 1);
		sum[0] = 0, ans = 0;
		for (register int i = 1; i <= n; ++i)
			if (s[i] == '0') sum[i] = sum[i - 1] + 1; else sum[i] = 0;
		for (register int i = 1; i <= n; ++i)
			if (s[i] == '1')
				for (register int j = i, t = 0; j < i + 20 && j <= n; ++j){
					t = (t << 1) | (s[j] ^ '0');
					if (i - sum[i - 1] <= j - t + 1) ++ans;
				}
		printf("%d\n", ans);
	}
}