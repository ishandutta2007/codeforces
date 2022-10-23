# include <bits/stdc++.h>
# define ll long long
using namespace std;
int t, n;
int a[100];
int main(){
	scanf("%d", &t);
	while (t--){
		ll nm1 = 1;
		scanf("%d", &n);
		ll s = 0;
		for (int i = 1; i <= n; i++){
			scanf("%d", a + i);
			while (a[i] % 2 == 0){
				a[i] /= 2;
				nm1 *= 2;
			}
			s += a[i];
		}
		ll ans = 0;
		for (int i = 1; i <= n; i++){
			ans = max(ans, s - a[i] + a[i] * nm1);
		}
		printf("%lld\n", ans);
	}
	return 0;
}