# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 200051;
const int P = 998244353;
int n;
ll ans;
ll a[MAXN], b[MAXN];
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%lld", a + i);
		a[i] = a[i] * i * (n - i + 1);
	}
	for (int i = 1; i <= n; i++) scanf("%lld", b + i);
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; i++) ans = (ans + (a[i] % P) * b[n - i + 1]) % P;
	printf("%lld\n", ans);
	return 0;
}