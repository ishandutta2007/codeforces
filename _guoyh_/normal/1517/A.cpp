# include <bits/stdc++.h>
# define ll long long
using namespace std;
int t;
ll n;
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%lld", &n);
		if (n % 2050){
			printf("-1\n");
			continue;
		}
		n /= 2050;
		int ans = 0;
		while (n){
			ans += n % 10;
			n /= 10;
		}
		printf("%d\n", ans);
	}
	return 0;
}