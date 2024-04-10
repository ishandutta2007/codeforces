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
const ll Log = 25;
ll Base = 41;
ll B2 = 101;


map<pll, ll> mp;
vector<ll> G[N];
ll a[N], ind[N];

bool CMP(ll i, ll j){
	return G[i] < G[j];
}
void Main(){
	mp.clear();
	ll n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i], ind[i] = i;
	for(int i = 1; i <= n; i++) G[i].clear();
	ll u, v;
	for(int i = 1; i <= m; i++){
		cin >> u >> v;
		G[v].pb(u);
	}
	for(int i = 1; i <= n; i++) if(G[i].size() == 0) a[i] = 0;
	for(int i = 1; i <= n; i++) sort(all(G[i])); //.clear();
	
	sort(ind + 1, ind + n + 1, CMP);
	ll ans = 0;
	ll sm = a[ind[1]];
	for(int i = 2; i <= n; i++){
		if(G[ind[i]] != G[ind[i - 1]]){
			ans = __gcd(ans, sm);
			sm = 0;
		}
		sm += a[ind[i]];
	}

	cout << __gcd(sm, ans) << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll T;
	cin >> T;
	while(T--) Main();
	return 0;
}
/*
2
10000000 9999999
*/