# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 300051;
int n;
ll x, ans;
ll a[MAXN];
ll f1[MAXN], f2[MAXN], f3[MAXN];
int main(){
	scanf("%d%lld", &n, &x);
	for (int i = 1; i <= n; i++) scanf("%lld", a + i);
	for (int i = 1; i <= n; i++){
		f1[i] = max(0ll, f1[i - 1]) + a[i];
		f2[i] = max(max(0ll, f1[i - 1]), f2[i - 1]) + a[i] * x;
		f3[i] = max(f2[i - 1], f3[i - 1]) + a[i];
		ans = max(ans, f1[i]);
		ans = max(ans, f2[i]);
		ans = max(ans, f3[i]);
	}
	printf("%lld\n", ans);
	return 0;
}