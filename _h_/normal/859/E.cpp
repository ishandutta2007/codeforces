#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long double ld;

const ll md = 1e9+7;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	int m = n+n;
	vi pek(m,-1);
	vector<vi> cs(m);
	rep(_,0,n){
		int a,b;
		cin >> a >> b;
		--a, --b;
		pek[a] = b;
		cs[b].push_back(a);
	}
	ll ans = 1;
	vector<bool> vis(m);
	vi nope(m,-1);
	function<int(int)> calc = [&](int v){
		vis[v] = 1;
		int ans = 1;
		trav(c, cs[v]) if(c != nope[v])
			ans += calc(c);
		return ans;
	};

	rep(i,0,m) if(!vis[i]){
		int j = i;
		while(pek[j] != -1 && !vis[pek[j]]){
			vis[j] = 1;
			j = pek[j];
		}
		vi cyc;
		do {
			cyc.push_back(j);
			j = pek[j];
		} while(j != -1 && j != cyc[0]);
		if(j == -1){
			ans = ans*calc(cyc[0])%md;
		} else {
			trav(v, cyc) nope[pek[v]] = v;
			trav(v, cyc) calc(v);
			if(j != pek[j]) ans = ans*2 % md;
		}
	}
	cout << ans << endl;
}