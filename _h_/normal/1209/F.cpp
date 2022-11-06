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
	int n, m;
	cin >> n >> m;
	vector<vector<pii>> ut(n);
	rep(i,1,m+1){
		string s = to_string(i);
		int x, y;
		cin >> x >> y;
		--x, --y;
		vi path(sz(s)+1);
		path[0] = x;
		path[sz(s)] = y;
		rep(i,1,sz(s)) path[i] = sz(ut)+i-1;
		ut.resize(sz(ut)+sz(s)-1);
		rep(i,0,sz(s)){
			ut[path[i]].emplace_back(path[i+1],s[i]-'0');	
		}
		reverse(all(path));
		rep(i,0,sz(s)){
			ut[path[i]].emplace_back(path[i+1],s[i]-'0');	
		}
	}
	int norg = n;
	n = sz(ut);
	vector<ll> val(n,-1);
	vi idx(n,-1);
	idx[0] = 0;
	val[0] = 0;
	vi cur = {0};
	vector<pii> todo(n, pii(1e6,0));
	while(!cur.empty()){
		vi nxt = {};
		trav(v,cur) trav(e,ut[v]) if(idx[e.first] == -1){
			if(todo[e.first].first == 1e6) nxt.push_back(e.first);
			pii xx = {idx[v], e.second};
			if( xx < todo[e.first] ){
				todo[e.first] = xx;
				val[e.first] = (10 * val[v] + e.second) % md;
			}
		}
		map<pii, int> ren;
		trav(u, nxt) ren[todo[u]];
		int ix = 0;
		trav(pa, ren) pa.second = ix++;
		trav(u, nxt) idx[u] = ren[todo[u]];
		cur = nxt;
	}
	rep(i,1,norg) cout << val[i] << endl;
}