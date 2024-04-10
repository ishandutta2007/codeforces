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

ll a[Maxn];
ll b[Maxn];
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	ll s = 0;
	for(int i = 0; i< n; i++){
		cin >> a[i];	
		b[i] = floor(1.0 * a[i] / 2.0);
		s += b[i];
	}
	for(int i = 0; i < n; i++){
		if((s < 0) && (a[i] % 2 != 0)){
			s ++;
			b[i] ++;
		}
	}
	for(int i = 0; i< n; i++) cout << b[i] << '\n';
	return 0;
}