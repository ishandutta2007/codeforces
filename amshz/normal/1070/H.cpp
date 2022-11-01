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

ll n, q, num[MAX1], sum;
unordered_map <string, int> p;
unordered_map <string, string> mp;
string s;

int main(){
	fast_io;
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> s;
		set <string> st;
		for (int j = 0; j < s.size(); ++j){
			string t = "";
			for (int k = j; k < s.size(); ++k){
				t += s[k];
				st.insert(t);
				mp[t] = s;
			}
		}
		for (string j : st)	p[j]++;
	}
	cin >> q;
	while (q--){
		cin >> s;
		cout << p[s] << sep;
		if (p[s] == 0)	cout << "-\n";
		else	cout << mp[s] << '\n';
	}
	return 0;
}