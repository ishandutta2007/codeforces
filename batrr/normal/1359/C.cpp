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
		ll h, c, t;
		scanf("%lld%lld%lld", &h, &c, &t);
		if(t + t <= h + c){
			printf("2\n");
		}else{
			ll l = 1, r = 2e6;
			while(l <= r){
				ll m = (l + r) / 2;
				if(m * h + (m - 1) * c >= t * (m + m - 1))
					l = m + 1;	
				else
					r = m - 1;
			}
			ll p = 1;
			for(ll i = max(1ll, l - 50); i <= r + 50; i++)
				if(abs(i * h + (i - 1) * c - t * (i + i - 1)) * (p + p - 1) < (i + i - 1) * abs(p * h + (p - 1) * c - t * (p + p - 1)))
					p = i;
			printf("%lld\n", p + p - 1);
		}		
	}
}