#include <bits/stdc++.h> 
using namespace std; 
/*
// ordered_set 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
*/
typedef long long       ll;
typedef long double     ld;
 
#define all(x)			(x).begin(),(x).end()
#define Sort(x)			sort(all(x))
#define A               first
#define B               second
#define sep             ' '
#define fast_io         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
const ll MAX1 = 2e5+7,
	     MOD = 998244353;
 
ll q, n, num[MAX1];
vector <ll> col[202];
set <ll> st;
 
int main(){
	fast_io;
	cin >> q;
	while (q--){
		cin >> n;
		st.clear();
		ll ans = 0;
		for (int i = 1; i <= 200; ++i)	col[i].clear();
		for (int i = 1; i <= n; ++i)	cin >> num[i], col[num[i]].push_back(i), st.insert(num[i]);
		for (int i : st){
			ans = max(ans, ll(col[i].size()));
			for (int j : st){
				// cout << i << sep << j << endl;
				ll pnt1 = 0, pnt2 = col[j].size()-1;
				for (int k = 0; k < col[i].size()/2; ++k){
					// cout << k << endl;
					while (pnt1 < col[j].size() && col[j][pnt1] <= col[i][k])	++pnt1;
					while (pnt2 >= 0 && col[j][pnt2] >= col[i][col[i].size()-k-1])	--pnt2;
					// cout << pnt1 << sep << pnt2 << endl;
					ans = max(ans, pnt2-pnt1+1+k*2+2);
					// cout << ans << endl;
				}
				// cout << endl;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}