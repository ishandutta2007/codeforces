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

const ll MOD = (ll) 179426549;
const ll MAXN = (ll) 3e5 + 10;
const ll INF = (ll) LONG_LONG_MAX;
const ld EPS = (ld) 1e-8;

vector<ll> G[MAXN], H[MAXN];
ll cnt[MAXN];

ll q[MAXN];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	ll n, m;
	cin >> n >> m;
	for(int i = 1; i<= n;i++) cin >> q[i];
	ll u, v;
	for(int i = 1; i<=m;i++){
		cin >> u >> v;
		G[u].pb(v);
		H[v].pb(u);
	}
	ll x = 1;
	for(auto adj : H[q[n]]){
		cnt[adj] ++;
	}
	ll ans = 0;
	for(int j = n-1; j>=1;j--){
		if(cnt[q[j]] == x){
			ans ++;
		} else {
			for(auto adj : H[q[j]]){
				cnt[adj] ++;
			}
			x ++;
		}
	}
	cout << ans;
	return 0;
}