# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
int t;
ll x1, x2, y1, y2;
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
		if (x2 - x1 < y2 - y1){
			swap(x1, y1);
			swap(x2, y2);
		}
		ll ans = (y2 - y1 - 1) * (y2 - y1) + (x2 - x1 - (y2 - y1) + 1) * (y2 - y1);
		printf("%lld\n", ans + 1);
	}
	return 0;
}