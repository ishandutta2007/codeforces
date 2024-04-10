#include <cstdio>
#include <cstring>
int T, n, m;
char s[100005], t[100005];
void solve(){
	scanf("%s%s", s + 1, t + 1), n = strlen(s + 1), m = strlen(t + 1);
	int p = m, ans = 0;
	while (t[p] == '0') --p;
	p += n - m;
	while (s[p] == '0') --p, ++ans;
	printf("%d\n", ans);
}
int main(){
	scanf("%d", &T);
	while (T--) solve();
}