# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 100051;
int n;
ll l[MAXN], r[MAXN];
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld%lld", l + i, r + i);
	sort(l + 1, l + n + 1);
	sort(r + 1, r + n + 1);
	ll ans = 0;
	for (int i = 1; i <= n; i++) ans += max(l[i], r[i]);
	printf("%lld\n", ans + n);
	return 0;
}