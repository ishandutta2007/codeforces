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

int n, m, x;

struct UF {
	vi t;
	vector<ll> w;
	vector<vi> gr;
	UF(){
		t.resize(n, -1);
		w.resize(n, 0);
		gr.resize(n);
	}
	int find(int a){
		return t[a] < 0 ? a : t[a] = find(t[a]);
	}
	ll val(int a){
		return w[find(a)];
	}
	bool uni(int a, int b){
		a = find(a), b = find(b);
		if(a == b) return false;
		if(t[a] < t[b]) swap(a, b);	
		if(sz(gr[a]) > sz(gr[b])) swap(gr[a], gr[b]);
		trav(x, gr[a]) gr[b].push_back(x);
		gr[a].clear();
		t[b] += t[a];
		w[b] += w[a] - x;
		w[a] = 0;
		t[a] = b;
		return true;
	}
};

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	cin >> n >> m >> x;

	UF uf;
	trav(a, uf.w) cin >> a;

	ll sum = 0;
	trav(x, uf.w) sum += x;
	if(sum < x * ll(n-1)){
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;

	vector<pii> es(m);
	vector<vi> gr(n);
	trav(pa, es){
	   	cin >> pa.first >> pa.second;
		--pa.first, --pa.second;
	}
	rep(i,0,m){
		uf.gr[es[i].first].push_back(i);
		uf.gr[es[i].second].push_back(i);
	}
	vi ans;
	rep(i,0,n) while(uf.val(i) >= x){
		int ii = uf.find(i);
		if(uf.gr[ii].empty()) break;
		int ix = uf.gr[ii].back();
		uf.gr[ii].pop_back();
		pii p = es[ix];
		if(uf.uni(p.first, p.second)) ans.push_back(ix);
	}
	rep(i,0,m){
		int u = es[i].first, v = es[i].second;
		if( uf.val(u) + uf.val(v) >= x && uf.uni(u, v) ) ans.push_back(i);
	}
	trav(x, ans) cout << x+1 << endl;
}