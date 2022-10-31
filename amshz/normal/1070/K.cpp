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

ll n, k, num[MAX1], sum;
vector <ll> ans;

int main(){
	fast_io;
	cin >> n >> k;
	for (int i = 0; i < n; ++i){
		cin >> num[i];
		sum += num[i];
	}
	if (sum%k != 0){
		cout << "No";
		return 0;
	}
	ll s1 = sum/k, cnt = 0;
	for (int i = 0; i < n; ++i){
		s1 -= num[i];
		++cnt;
		if (s1 < 0){
			cout << "No";
			return 0;
		}
		if (s1 == 0)	ans.push_back(cnt), cnt = 0, s1 = sum/k;
	}
	cout << "Yes\n";
	for (int i : ans)	cout << i << sep;
	return 0;
}