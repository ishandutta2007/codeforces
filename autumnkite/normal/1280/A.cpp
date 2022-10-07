#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
const int N = 1000005, P = 1000000007;
int n, m, ans;
char s[N];
void solve(){
	scanf("%d%s", &n, s + 1), ans = m = strlen(s + 1);
	for (register int i = 1; i <= n; ++i){
		int w = (s[i] ^ '0') - 1, l = m - i;
		for (register int j = 1; j <= w * l && m < n; ++j) s[++m] = s[i + j];
		ans = (ans + 1ll * w * (ans - i + P)) % P;
	}
	printf("%d\n", ans);
}
int main(){
	int T;
	scanf("%d", &T);
	while (T--) solve();
}