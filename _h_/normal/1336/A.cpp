#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (b);)
#define trav(x,v) for(auto &x : (v))
#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);

	int n, k;
	cin >> n >> k;

	vector<vi> gr(n);
	rep(_,1,n){
		int u, v;
		cin >> u >> v;
		--u, --v;
		gr[u].push_back(v);
		gr[v].push_back(u);
	}
	vi h(n), desc(n);
	function<void(int,int)> dfs = [&](int v, int p){
		trav(u, gr[v]) if(u != p){
			h[u] = h[v]+1;
			dfs(u, v);
			desc[v] += 1 + desc[u];
		}
	};
	dfs(0,-1);

	vi w(n);
	rep(i,0,n) w[i] = h[i] - desc[i];
	sort(all(w));
	reverse(all(w));

	ll ans = 0;
	rep(i,0,k) ans += w[i];
	cout << ans << endl;
}