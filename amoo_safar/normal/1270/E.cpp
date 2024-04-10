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

ll x[Maxn], y[Maxn];
vector<ll> A;
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, k;
	cin >> n;
	if(n == 2) return cout << "1\n1\n", 0;
	for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
	ll g = 0;
	ll d= 0;
	for(int i = 0 ; i < n; i++){
		for(int j = i + 1; j < n; j++){
			d = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
			g = __gcd(g, d);
		}
	}
	ll pw = 1;
	while(g % pw == 0) pw *= 2;
	pw /= 2ll;
	
	
	for(int i = 1; i < n; i++){
		int j = 0;
		d = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
		d /= pw;
		if(d & 1) A.pb(i + 1);
	}
	
	cout << A.size() << '\n';
	for(auto x : A) cout << x << ' ';
	
	return 0;
}