# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
int t;
int main(){
	scanf("%d", &t);
	while (t--){
		ll k;
		int x;
		scanf("%lld%d", &k, &x);
		ll ans = k * 9 + x - 9;
		printf("%lld\n", ans);
	}
	return 0;
}