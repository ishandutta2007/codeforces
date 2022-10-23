# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
ll n;
int q;
int main(){
	scanf("%lld%d", &n, &q);
	while (q--){
		ll u, v;
		scanf("%lld%lld", &u, &v);
		u--;
		v--;
		ll nw = u * n + v;
		ll ans;
		if ((u + v) & 1) ans = nw / 2 + ((n * n + 1) / 2) + 1;
		else ans = nw / 2 + 1;
		printf("%lld\n", ans);
	}
	return 0;
}