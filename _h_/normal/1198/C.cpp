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

void solve(){
	int n, m;
	cin >> n >> m;

	vector<vector<pii>> gr(3*n);
	rep(i,0,m){
		int u, v;
		cin >> u >> v;
		--u, --v;
		gr[v].emplace_back(u, i);
		gr[u].emplace_back(v, i);
	}
	vi edges;
	vector<bool> matched(3*n, false);
	vi vertices;
	rep(i,0,3*n) if(!matched[i]){
		trav(e, gr[i]) if(!matched[e.first]){
			matched[e.first] = true;
			matched[i] = true;
			edges.push_back(e.second);
			if(sz(edges) == n){
				cout << "Matching" << endl;
				trav(e, edges) cout << e+1 << ' ';
				cout << endl;
				return;
			}
			goto ok;
		}
		vertices.push_back(i);
		if(sz(vertices) == n){
			cout << "IndSet" << endl;
			trav(v, vertices) cout << v+1 << ' ';
			cout << endl;
			return;
		}
		ok: ;
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	rep(_,0,t) solve();
}