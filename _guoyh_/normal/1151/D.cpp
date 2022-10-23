# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 100051;
int n;
ll s1, s2;
ll a[MAXN], b[MAXN], c[MAXN];
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%lld%lld", a + i, b + i);
		s1 += a[i];
		s2 += b[i];
		c[i] = a[i] - b[i];
	}
	ll ans = n * s2 - s1;
	sort(c + 1, c + n + 1);
	for (int i = 1; i <= n; i++) ans += c[n - i + 1] * i;
	printf("%lld\n", ans);
	return 0;
}