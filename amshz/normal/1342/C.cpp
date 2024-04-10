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
 
const ll MAX1 = 4e4+10,
         MOD = 1e9+7;
 
ll q, T, a, b, l, r, num[MAX1], part[MAX1];
string s;
 
int main(){
    fast_io;
    
    cin >> T;
    while (T--){
    	cin >> a >> b >> q;
    	fill(num, num+MAX1, 0);
    	fill(part, part+MAX1, 0);
    	ll flag = 0;
    	for (ll i = 1; i <= a*b; ++i){
    		if ((i%a)%b != (i%b)%a)	num[i] = 1, ++flag;
    		part[i] = part[i-1]+num[i];
		}
    	while (q--){
    		cin >> l >> r;
    		ll ans = 0;
    		ll x = ((l+a*b-1)/(a*b))*(a*b), y = a*b*(r/(a*b));
    		if (x > y){
    			cout << part[(r%(a*b))]-part[(l%(a*b))-1] << sep;
    			continue;
			}
    		ans = (y-x)/(a*b) * flag;
    		l = l%(a*b);
    		if (l == 0)	l = a*b;
    		r = r%(a*b);
    		ans += part[a*b]-part[l-1];
    		ans += part[r];
			cout << ans << sep;
		}
		cout << '\n';
	}
    return 0;
}
/*                 now or never                 */