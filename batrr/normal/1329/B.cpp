#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int main()
{
	int t;
	scanf("%d", &t);
	while(t--){
		ll d, mod, ans = 1;
		scanf("%lld%lld", &d, &mod);
		for(int i = 0;; i++){
			ll l = (1 << i);
			ll r = (1 << (i + 1)) - 1;
			r = min(r, d);
			if(r < l)
				break;
			ans = ((r - l + 2) * ans) % mod;			
		}
		ans = (ans + mod - 1) % mod;
		printf("%lld\n", ans);
	}
}