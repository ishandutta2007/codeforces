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

//const ll Mod = 1000000007LL;
ll Mod;
const int Maxn = 1e6 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

ll f[Maxn];

ll mul(ll a, ll b){
	return (a * b) % Mod;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n >> Mod;
	f[0] = 1;
	for(int i = 1; i < Maxn; i++) f[i] = mul(f[i - 1], i);
	
	ll ans = 0;
	for(int l = 1; l <= n; l++){
		//cerr << l << '\n';
		ans += mul(f[l], mul(n - l + 1, f[n - l + 1]));
	}
	cout << ans % Mod<< '\n';
	return 0;
}