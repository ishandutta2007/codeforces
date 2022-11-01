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
 
const ll MAX1 = 5e5+10,
         MOD = 1e9+7;
 
ll n, q, k, ans[MAX1];
 
int main(){
    fast_io;
    ans[1] = 0;
    for (ll i = 3; i < MAX1; i += 2){
    	ans[i] = ans[i-2]+(i/2)*(i-1)*4;
	}
	cin >> q;
	while (q--){
		cin >> n;
		cout << ans[n] << '\n';
	}
    return 0;
}
/*                 now or never                 */