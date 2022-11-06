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

void solve(){
	int n, m;
	cin >> n >> m;
	vector<vi> bs(n, vi(m));
	trav(v, bs) trav(x, v) cin >> x;
	vector<pii> ps;
	rep(i,0,n) rep(j,0,m) ps.emplace_back(i,j);
	sort(all(ps), [&](pii p, pii q){
		return bs[p.first][p.second] < bs[q.first][q.second];
	});
	vector<vi> assig(n, vi(m, -1));
	rep(i,0,m) assig[ps[i].first][ps[i].second] = i;
	rep(i,0,n){
		vi ans(m, -1);
		vi ls;
		rep(j,0,m) if(assig[i][j] >= 0) ans[assig[i][j]] = bs[i][j];
		else ls.push_back(bs[i][j]);
		int ix = 0;
		trav(x, ans) if(x == -1) x = ls[ix++];
		trav(x, ans) cout << x << " ";
		cout << endl;
	}
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