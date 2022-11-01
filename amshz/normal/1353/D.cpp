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
 
ll n, q, k, ans[MAX1], flag;
set <pair <ll, ll> > st;
 
int main(){
    fast_io;
    cin >> q;
    while (q--){
    	cin >> n;
    	st.clear();
    	st.insert({n, 1});
    	flag = n;
    	ll cnt = 1;
    	while (cnt <= n){
    		auto it = st.lower_bound({flag, 0});
    		if (it == st.end()){
    			--flag;
    			continue;
			}
			ll x = it -> B, y = it -> A;
			st.erase(it);
			ans[x+(y-1)/2] = cnt;
			++cnt;
			st.insert({(y-1)/2, x});
			st.insert({y/2, x+(y-1)/2+1});
		}
		for (int i = 1; i <= n; ++i)	cout << ans[i] << sep;
		cout << '\n';
	}
    return 0;
}
/*                 now or never                 */