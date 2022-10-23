# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
int t;
int main(){
	scanf("%d", &t);
	while (t--){
		ll mx = 0, s = 0;
		for (int i = 0; i < 3; i++){
			ll x;
			scanf("%lld", &x);
			s += x;
			mx = max(mx, x);
		}
		if (s - mx >= mx - 1) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}