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
 
const ll Mod = 1e9 + 7;
const ll Inf = 2242545357980376863LL;
const ll Log = 20;
//const ll N = 1ll << Log;
const int Maxn = 3e5 + 10;
const int Base = 101;
typedef pair<pll, ll> node;

vector<ll> V;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	ll g = 0;
	for(ll i = 2; i*i <= n; i++){
		if(n % i == 0){
			g = __gcd(g, __gcd(i, n/i));
		}
	}
	if(g) cout << g;
	else cout << n;
	return 0;
}