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
 
ll q, n;
string s[10];
 
char find(ll a, ll b){
	ll adad = s[a][b] - '0';
	return '0'+(adad%9+1);
}
 
int main(){
	fast_io;
	cin >> q;
	while (q--){
		for (int i = 0; i < 9; ++i){
			cin >> s[i];
		}
		s[0][0] = find(0, 0);
		s[1][3] = find(1, 3);
		s[2][6] = find(2, 6);
		s[3][1] = find(3, 1);
		s[4][4] = find(4, 4);
		s[5][7] = find(5, 7);
		s[6][2] = find(6, 2);
		s[7][5] = find(7, 5);
		s[8][8] = find(8, 8);
		for (int i = 0; i < 9; ++i)	cout << s[i] << endl;
		
	}
	return 0;
}