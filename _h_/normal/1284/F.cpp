#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define trav(x,v) for(auto &x : (v))
#define sz(v) (int)(v).size()
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

struct UF {
	vi t;
	UF(int n){
		t.resize(n, -1);
	}
	int find(int a){
		return t[a] < 0 ? a : t[a] = find(t[a]);
	}
	void uni(int a, int b){
		a = find(a), b = find(b);
		if(a == b) return;
		if(t[b] < t[a]) swap(a,b);
		t[b] += t[a];
		t[a] = b;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<vi> t1(n), t2(n);
	rep(_,1,n){
		int a, b;
		cin >> a >> b;
		--a, --b;
		t1[a].push_back(b);
		t1[b].push_back(a);
	}
	int lg = 25;
	vector<vi> jmp(lg, vi(n));
	vi h(n);
	function<void(int)> dfs0 = [&](int v){
		trav(u,t1[v]) if(u != jmp[0][v]){
			h[u] = h[v]+1;
			jmp[0][u] = v;
			dfs0(u);
		}
	};
	dfs0(0);
	rep(t,1,lg) rep(i,0,n) jmp[t][i] = jmp[t-1][jmp[t-1][i]];
	rep(_,1,n){
		int a, b;
		cin >> a >> b;
		--a, --b;
		t2[a].push_back(b);
		t2[b].push_back(a);
	}

	auto hopp = [&](int v, int d){
		rrep(t,0,lg) if(d & (1<<t)){
			v = jmp[t][v];
		}
		return v;
	};

	auto lca = [&](int a, int b){
		if(h[a] < h[b]) swap(a,b);
		a = hopp(a, h[a] - h[b]);
		if(a == b) return a;
		rrep(t,0,lg){
			int a1 = jmp[t][a];
			int b1 = jmp[t][b];
			if(a1 != b1){
				a = a1;
				b = b1;
			}
		}
		return jmp[0][a];
	};

	UF uf(n);

	vector<vi> ans;

	auto addans = [&](int a, int b, int c, int d){
		uf.uni(a,b);
		ans.push_back({a,b,c,d});
	};

	auto dostuff = [&](int u, int v){
		int r = uf.find(u);
		int c = lca(u, v);	
		if(uf.find(c) == r){
			if(jmp[0][v] == c){
				return pii(v, c);	
			}
			rrep(t,0,lg){
				if(h[v]-h[c] <= (1<<t)) continue;
				int m = jmp[t][v];
				if(uf.find(m) == r) c = m;
				else v = m;
				if(jmp[0][v] == c){
					return pii(v, c);	
				}
			}
		} else {
			if(jmp[0][u] == c){
				return pii(u, c);	
			}
			rrep(t,0,lg){
				if(h[u]-h[c] <= (1<<t)) continue;
				int m = jmp[t][u];
				if(uf.find(m) == r) u = m;
				else c = m;
				if(jmp[0][u] == c){
					return pii(u, c);	
				}
			}

		}
	};

	function<void(int, int)> dfs = [&](int u, int p){
		trav(v, t2[u]) if(v != p){
			dfs(v, u);
			pii p = dostuff(v, u);
			addans(p.first, p.second, v, u);
		}
	};
	dfs(0, -1);

	cout << n-1 << endl;
	trav(v, ans){
		trav(x, v) cout << x+1 << " ";
		cout << endl;
	}
}