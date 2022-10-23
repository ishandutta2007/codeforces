# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 100051;
int n;
ll ans;
int a[MAXN];
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int i = 1; i <= n; i++) ans += 1ll * a[i] * (n - a[i] + 1);
	for (int i = 1; i <= n - 1; i++){
		ans -= 1ll * min(a[i], a[i + 1]) * (n - max(a[i], a[i + 1]) + 1);
	}
	printf("%lld\n", ans);
	return 0;
}