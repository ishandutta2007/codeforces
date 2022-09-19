#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ld PI = 3.14159265359;

const ll MOD = (ll) 998244353ll;
const ll MAXN = (ll) 1e3 + 10;
const ll INF = (ll) LONG_LONG_MAX;
const ld EPS = (ld) 1e-8;

ll a[MAXN][MAXN];

ll lr[MAXN][MAXN];
ll br[MAXN][MAXN];
ll lc[MAXN][MAXN];
ll bc[MAXN][MAXN];

set<ll> st;
map<ll, ll> mp;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) for(int j = 1; j<=m;j++) cin >> a[i][j];
	for(int i = 1; i <= n; i++){
		st.clear();
		mp.clear();
		for(int j = 1; j<=m;j++) st.insert(a[i][j]);
		ll cnt = 0;
		for(auto x : st){
			mp[x] = cnt;
			cnt ++;
		}
		
		for(int j = 1; j<=m;j++){
			lr[i][j] = mp[a[i][j]];
			br[i][j] = cnt - lr[i][j] - 1;
		}
	}
	
	for(int j = 1; j <= m; j++){
		st.clear();
		mp.clear();
		for(int i = 1; i<=n;i++) st.insert(a[i][j]);
		ll cnt = 0;
		for(auto x : st){
			mp[x] = cnt;
			cnt ++;
		}
		
		for(int i = 1; i<=n;i++){
			lc[i][j] = mp[a[i][j]];
			bc[i][j] = cnt - lc[i][j] - 1;
		}
	}
	for(int i = 1; i<=n;i++){
		for(int j =1 ;j<=m;j++){
		cout << 1 + max(lr[i][j], lc[i][j]) + max(br[i][j], bc[i][j]) << " ";
		}
		cout << '\n';
	}
	return 0;
}