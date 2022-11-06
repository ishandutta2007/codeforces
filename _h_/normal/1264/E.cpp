// written by aitch
// on 2019 12/05 at 14:35:01
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

	int n, m;
	cin >> n >> m;

	vector<string> ans(n,string(n,'0'));
	vector<vi> gr(n);
	rep(_,0,m){
		int u, v;
		cin >> u >> v;
		--u, --v;
		ans[u][v] = '1';
	}
	vector<pii> es;
	rep(i,0,n) rep(j,0,i) if(ans[i][j]=='0' && ans[j][i]=='0')
		es.emplace_back(i,j);

	vi deg(n);
	rep(i,0,n) deg[i] = (int)count(all(ans[i]), '1');

	// greedy first approximation
	
	trav(pa, es) if(deg[pa.first] < deg[pa.second]){
		ans[pa.first][pa.second] = '1';
		deg[pa.first] += 1;
	} else {
		swap(pa.first, pa.second);
		ans[pa.first][pa.second] = '1';
		deg[pa.first] += 1;
	}

	auto flipint = [&](int &i, int &j){
		--deg[i];
		++deg[j];
		assert(ans[i][j] == '1' && ans[j][i] == '0');
		swap(ans[i][j], ans[j][i]);
		swap(i,j);
	};
	auto flip = [&](pii &pa){
		flipint(pa.first, pa.second);
	};

	vector<vi> se(n);
	rep(i,0,sz(es)){
		se[es[i].first].push_back(i);
		se[es[i].second].push_back(i);
	}
	while(true){
		bool foo = false;
		trav(pa, es){
			if(deg[pa.first] > deg[pa.second]+1){
				foo = true;
				flip(pa);
			}
		}
		if(foo) continue;

		vi perm(n);
		iota(all(perm),0);
		sort(all(perm), [&](int i, int j){
			return deg[i] > deg[j];
		});
		vi pek(n, -1);
		function<bool(int,int)> dfs = [&](int v,int cur){
			trav(e, se[v]) if(v == es[e].first && 
				pek[es[e].second] == -1){
				pek[es[e].second] = e;
				if(dfs(es[e].second, cur)) return true;
			}
			if(deg[v] <= cur-2){
				vi ls;
				while(pek[v] != -2){
					ls.push_back(pek[v]);
					v = es[pek[v]].first;
				}
				trav(e, ls) flip(es[e]);
				return true;
			}
			return false;
		};
		trav(v, perm){
			pek[v] = -2;
			if(dfs(v, deg[v])) goto done;
		}
		break;
		done: ;
	}

	trav(s, ans) cout << s << endl;
}