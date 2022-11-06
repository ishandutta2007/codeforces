// written by aitch
// on 2019 12/17 at 16:05:00
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

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	 
	// watch out for overflow
	
	vi a(n);
	trav(x, a) cin >> x;

	ll tota = 0;
	trav(x, a) tota += x;

	int q;
	cin >> q;

	map<pii, int> ts;

	vi free(n);
	int totfree = 0;

	rep(_,0,q){
		int s, t, u;
		cin >> s >> t >> u;
		--s, --u;

		if(ts.count(pii(t,s))){
			int u1 = ts[pii(t,s)];
			ts.erase(pii(t,s));
			totfree -= min(a[u1], free[u1]);
			--free[u1];
			totfree += min(a[u1], free[u1]);
		}
		if(u >= 0){
			ts[pii(t,s)] = u;
			totfree -= min(a[u], free[u]);
			++free[u];
			totfree += min(a[u], free[u]);
		}
		cout << tota - totfree << endl;
	}
}