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
const int Maxn = 5e5 + 10;
const int Maxm = 86500;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

vector< pair<pll, pll> > V, V2;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	ll x, y, z;
	for(int i = 0; i < n; i++){
		cin >> x >> y >> z;
		V.pb({{x, y}, {z, i + 1}});
	}
	sort(all(V));
	
	ll m;
	m = V.size();
	V2.clear();
	ll i = 0;
	while(i < m){
		if(i + 1 < m && V[i].F == V[i + 1].F){
			cout << V[i].S.S << " " << V[i + 1].S.S << '\n';
			i += 2;
		} else {
			V2.pb(V[i]);
			i += 1;
		}
	}
	V.clear();
	V.swap(V2);
	m = V.size();
	i = 0;
	while(i < m){
		if(i + 1 < m && V[i].F.F == V[i + 1].F.F){
			cout << V[i].S.S << " " << V[i + 1].S.S << '\n';
			i += 2;
		} else {
			V2.pb(V[i]);
			i += 1;
		}
	}
	m = V2.size();
	for(int j = 0; j < m; j+= 2) cout << V2[j].S.S << " " << V2[j + 1].S.S << '\n';
	return 0;
}