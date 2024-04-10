#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < b; ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define trav(x, v) for(auto &x : v)
#define all(v) (v).begin(),(v).end()
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

const ll md = 998244353;

struct FT {
	vi t;
	FT(int n){
		t.resize(n+1, 0);
	}	
	void upd(int pos){
		for(++pos; pos < sz(t); pos += pos & -pos) t[pos]++;
	}
	int que(int to){
		int ans = 0;
		for(; to; to -= to & -to) ans += t[to];
		return ans;
	}
};

void solve(){
	int n;
	cin >> n;
	vi as(n); 
	trav(x, as) cin >> x;

	vector<ll> pre(n+1); // value of putting a string of PC's ending at i
	rep(i,0,n) pre[i+1] = -as[i] - pre[i];

	vector<vector<ll>> ls(n+1), rs(n+1);

	ll dif = 0; // sum of Ps minus sum of Cs
	rep(i,0,n+1){ // just C's to start with
		ls[i].push_back(pre[i] - dif);
		if(i < n) dif -= as[i];
	}
	dif = as[0];
	rep(i,1,n+1){ // PCC...
		if(i >= 3) ls[i].push_back(pre[i] - dif);
		if(i < n) dif -= as[i];
	}
	// now symmetric case
	dif = 0;
	rrep(i,0,n+1){ // just P's at end
		rs[i].push_back(dif + pre[i]);
		if(i > 0) dif += as[i-1];
	}
	dif = -as[n-1];
	rrep(i,0,n){ // ...PPC
		if(i <= n-3) rs[i].push_back(dif + pre[i]);
		if(i > 0) dif += as[i-1];
	}

	map<ll, int> ren;
	trav(v, ls) trav(x, v) ren[x] = 0;
	trav(v, rs) trav(x, v) ren[x] = 0;
	int ix = 0;
	trav(pa, ren) pa.second = ix++;

	// want # of pairs (i, x) (j, y) with i <= j and x < y
	ll ans = 0;

	rep(t,0,2){ // parity of first PC let's say
		FT ft(ix);
		rep(i,0,n+1) if(i % 2 == t){
			trav(x, ls[i]){
				ft.upd(ren[x]);
			}
			trav(y, rs[i]){
				int res = ft.que(ren[y]);
				ans += res;
			}
		}
	}

	vector<ll> dumb(n+1);
	rep(i,0,n) dumb[i+1] = dumb[i] + as[i];

	rep(i,2,n-1){
		ans += dumb[i] * 2 > dumb[n];
	}

	cout << ans % md << endl;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	rep(_,0,n){
		solve();
	}
}