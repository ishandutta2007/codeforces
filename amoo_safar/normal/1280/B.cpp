#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll Mod = 1000000007LL;
const int Maxn = 60 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

str s[Maxn];

int MAIN(){
	ll n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> s[i];
	ll fl = 0, fl2 = 0;
	for(int i = 0; i < n; i++) for(auto x : s[i]) if(x == 'A') fl = 1;
	for(int i = 0; i < n; i++) for(auto x : s[i]) if(x == 'P') fl2 = 1;
	if(!fl2) return cout << "0\n", 0;
	if(!fl) return cout << "MORTAL\n", 0;
	
	ll ans = 4;
	ll res = 0;
	fl = 1;
	for(int i = 0; i < m; i++) fl &= (s[0][i] == 'A');
	res |= fl;
	fl = 1;
	for(int i = 0; i < m; i++) fl &= (s[n - 1][i] == 'A');
	res |= fl;
	fl = 1;
	for(int i = 0; i < n; i++) fl &= (s[i][0] == 'A');
	res |= fl;
	fl = 1;
	for(int i = 0; i < n; i++) fl &= (s[i][m - 1] == 'A');
	res |= fl;
	
	
	if(res) return cout << "1\n", 0;
	
	for(int i = 0; i < n; i++){
		fl = 0;
		for(auto x : s[i]) if(x == 'P') fl = 1;
		if(!fl) return cout << "2\n", 0;
	}
	for(int j = 0; j < m; j++){
		fl = 0;
		for(int i = 0; i < n; i++) if(s[i][j] == 'P') fl = 1;
		if(!fl) return cout << "2\n", 0;
	}
	
	if((s[0][0]=='A')|| (s[0][m - 1]=='A')|| (s[n - 1][0]=='A')|| (s[n - 1][m - 1]=='A')) return cout << "2\n", 0;
	
	fl = 0;
	for(int i = 0; i < m; i++) fl |= (s[0][i] == 'A');
	for(int i = 0; i < m; i++) fl |= (s[n - 1][i] == 'A');
	for(int i = 0; i < n; i++) fl |= (s[i][0] == 'A');
	for(int i = 0; i < n; i++) fl |= (s[i][m - 1] == 'A');
	if(fl) cout << "3\n";
	else cout << "4\n";
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T--) MAIN();
	return 0;
}