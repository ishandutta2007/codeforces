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
const int N = 2e5 + 10;
const ll Inf = 2242545357980376863LL;
const ll Log = 30;

vector<ll> G[N];
vector<ll> V;

ll mk[N], ans;
ll sub[N];
int DFS(ll u, ll p, ll d = 0){
	sub[u] = 1;
	for(auto adj : G[u]) if(adj != p) sub[u] += DFS(adj, u, d + 1);
	V.pb(d - (sub[u]- 1));
	return sub[u];
}
void dfs(ll u, ll p, ll d = 0){
	if(mk[u]) d++;
	else ans += d;

	for(auto adj : G[u]) if(adj != p) dfs(adj, u, d);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n , k;
	cin >> n >> k;
	for(int i = 1; i < n; i++){
		ll u, v;
		cin >> u >> v;
		G[u].pb(v);
		G[v].pb(u);
	}
	DFS(1, -1);
	sort(all(V));
	reverse(all(V));
	
	for(int i = 0; i < k; i++) ans += V[i];
	
cout << ans << '\n';
	return 0;
}