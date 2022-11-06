// written by aitch
// on 2019 09/23 at 17:44:31
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;

const ll md = 1e9+7;

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<ll> xs(n);
	trav(x, xs) cin >> x;

	vector<vi> gr(n);
	rep(_,1,n){
		int a, b;
		cin >> a >> b;
		--a, --b;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}

	ll ans = 0;
	
	function<void(int, int, map<ll,int>)> dfs = [&](int v, int par, 
		map<ll,int> cnt){
		map<ll,int> nxt;
		ll x = xs[v];
		nxt[x] += 1;
		trav(y, cnt)
			nxt[__gcd(x,y.first)] += y.second;
		trav(pa, nxt)
			ans += pa.first % md * pa.second % md;
		trav(u, gr[v]) if(u != par)
			dfs(u, v, nxt);
	};
	dfs(0, -1, map<ll,int>());
	ans %= md;
	cout << ans << endl;
}