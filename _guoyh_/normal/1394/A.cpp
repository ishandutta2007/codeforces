# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int NR = 100051;
ll n, d, m, ans;
ll a[NR], s[NR];
int main(){
	scanf("%lld%lld%lld", &n, &d, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", a + i);
	sort(a + 1, a + n + 1);
	int pos = upper_bound(a + 1, a + n + 1, m) - a;
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	for (int i = 0; i < pos; i++){
		if ((n - pos + 1) * d < pos - i - 1) continue;
		ll f = (n - i + d) / (d + 1);
		ll nw = s[pos - 1] - s[pos - 1 - i] + s[n] - s[n - f];
		ans = max(ans, nw);
	}
	printf("%lld\n", ans);
	return 0;
}