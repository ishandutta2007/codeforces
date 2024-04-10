# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 100051;
int t, n;
ll a[MAXN], b[MAXN];
int main(){
	// freopen("1.in", "r", stdin);
	scanf("%d", &t);
	while (t--){
		int ans = 0;
		int lid = -1;
		ll lt = 0, lx = 0, ls = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%lld%lld", a + i, b + i);
		a[n + 1] = 1e17;
		for (int i = 1; i <= n; i++){
			if (abs(lx - ls) <= a[i] - lt){
				ans += (lid == i - 1);
				lt = a[i];
				ls = lx;
				lx = b[i];
				lid = i;
				ans += (i == n);
			} else {
				if (lx > ls){
					ans += (b[i] <= lx && ls + (a[i + 1] - lt) >= b[i] && ls + (a[i] - lt) <= b[i]);
				} else {
					ans += (b[i] >= lx && ls - (a[i + 1] - lt) <= b[i] && ls - (a[i] - lt) >= b[i]);
				}
			}
		}
		printf("%d\n", ans);
	}	
	return 0;
}