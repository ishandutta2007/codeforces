#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long       ll;
 
#define all(x)            (x).begin(),(x).end()
#define Sort(x)            sort(all(x))
#define A               first
#define B               second
#define sep             ' '
#define fast_io         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define set_random     mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count())
 
const ll MAX1 = 1e5+10,
         MOD = 1e9+7;
 
ll n, q, k, a[MAX1], b[MAX1];
 
int main(){
    fast_io;
    cin >> q;
    while (q--){
    	cin >> n >> k;
    	ll sum = 0;
    	for (int i = 0; i < n; ++i)	cin >> a[i], sum += a[i];
    	for (int i = 0; i < n; ++i)	cin >> b[i];
    	sort(a, a+n);
    	sort(b, b+n);
    	ll cnt = 0;
    	while (k){
    		if (b[n-cnt-1] <= a[cnt])	break;
    		sum += b[n-cnt-1] - a[cnt];
    		// cout << k << sep << sum << '\n';
    		++cnt;
    		--k;
		}
		cout << sum << '\n';
	}
    return 0;
}
/*                 now or never                 */