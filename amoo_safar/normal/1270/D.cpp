#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const ll Mod = 1000000007LL;
const int Maxn = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

map<ll, ll> mp;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, k;
	cin >> n >> k;
	n = k + 1;
	for(int i = 1; i <= n; i++){
		cout << "? ";
		for(int j = 1; j <= n; j++) 
			if(i != j) cout << j << ' ';
		cout << endl;
		ll p, res;
		cin >> p >> res;
		mp[res] ++;
	}
	ll fl = 0;
	for(auto x : mp){
		if(fl == 0){
			fl = 1;
			continue;
		}	
		cout << "! " << x.S << '\n' << flush;
	}
	return 0;
}