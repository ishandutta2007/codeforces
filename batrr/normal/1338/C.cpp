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

/*
00
00
00

10
01
11

01
11
10

11
10
01



10
01
11
*/
void solve(){
	ll n, k;
	scanf("%lld", &n);
	n--;
	k = n / 3;
	vector< ll > v(3, 0);
	for(int i = 0;; i += 2){
		ll x = (1ll << i);
		if(x <= k)
			k -= x;
		else{
			for(int j = 0; j < i; j += 2){			
				ll t = k % 4;
				k /= 4;
				if(t == 1){                  
					v[0] += (1ll << j);
					v[1] += (1ll << (j + 1));
					v[2] += (1ll << j);
					v[2] += (1ll << (j + 1));
				}
				if(t == 2){
					v[0] += (1ll << (j + 1));
					v[1] += (1ll << j);
					v[1] += (1ll << (j + 1));
					v[2] += (1ll << j);
				}
				if(t == 3){
					v[0] += (1ll << j);
					v[0] += (1ll << (j + 1));
					v[1] += (1ll << j);
					v[2] += (1ll << (j + 1));
				}
			}			
			v[0] += (1ll << i);
			v[1] += (1ll << (i + 1));
			v[2] += (1ll << i);
			v[2] += (1ll << (i + 1));	
			break;
		}
	}
	printf("%lld\n", v[n % 3]);
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		solve();
}