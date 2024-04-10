#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " : " << x << '\n'

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll, ll> pll;

const ll Mod = 1000000007LL;
const int N = 5e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

vector<ll> G[N];

ll a[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n, m;
	cin >> n >> m;
	ll u, v;
	for(int i =0 ; i < m; i++){
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	for(int i = 1; i <= n; i++) cin >> a[i];

	for(int i = 1; i <= n; i++){
		int mx = 1;
		sort(all(G[i]), [&](int i, int j){
			return a[i] < a[j];
		});
		for(auto x : G[i]) if(a[x] == mx) mx ++;
		if(mx != a[i]) return cout << -1, 0;
	}
	vector<ll> V(n);
	iota(all(V), 1);
	sort(all(V), [&](int i, int j){
		return a[i] < a[j];
	});
	for(auto x : V) cout << x << ' ';
	cout << '\n';
	return 0;
}