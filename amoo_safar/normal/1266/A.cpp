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
const int Maxn = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T--){
		str s;
		cin >> s;
		int cnt = 0;
		int sm = 0;
		int f = 0;
		for(auto x : s) sm += (x - '0');
		for(auto x : s) cnt += ((x-'0') % 2 == 0);
		for(auto x : s) f += ((x-'0') == 0);
		if(f && cnt > 1 && sm %3 ==0) cout<<"red\n";
		else cout << "cyan\n";
	}
	return 0;
}