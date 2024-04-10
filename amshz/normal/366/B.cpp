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

const ll MAX1 = 1e5+7,
	     MOD = 1e9+7;

ll n, k, num[MAX1], ans[MAX1];

int main(){
	fast_io;
	cin >> n >> k;
	for (int i = 0; i < n; ++i)	cin >> num[i], ans[i%k] += num[i];
	ll flag = -1, MN = 1e18;
	for (int i = 0; i < k; ++i){
		if (ans[i] < MN)	MN = ans[i], flag = i+1;
	}
	cout << flag;
	return 0;
}