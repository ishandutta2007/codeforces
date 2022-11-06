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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<vi> gr(n);
	rep(i,1,n){
		int a, b;
		cin >> a >> b;
		--a, --b;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	vi par(n, -1), sl(n, 1);
	function<void(int)> dfs1 = [&](int v){
		trav(u, gr[v]) if(u != par[v]){
			par[u] = v;
			dfs1(u);
			sl[v] += sl[u];
		}
	};
	dfs1(0);
	vi cs;
	rep(i,0,n){
		trav(j, gr[i]){
			int x = 0;
			if(j == par[i]) x = n - sl[i];
			else x = sl[j];
			if(2*x > n) goto done;
		}
		cs.push_back(i);
		done: ;
	}
	vi x, y, y2;
	int c = -1, pr = -1, d = -1;
	function<void(int,int)> dfs = [&](int v, int par){
		trav(u, gr[v]) if(u != par) dfs(u, v);
		x.push_back(c);
		y.push_back(pr);
		y2.push_back(v);
		pr = v;
		x.push_back(v);
		y.push_back(par);
		y2.push_back(d);
	};

	auto fun = [&](int anc, int v){
		c = anc;
		pr = v;
		d = v;
		trav(u, gr[v]) if(u != anc)
			trav(w, gr[u]) if(w != v)
				dfs(w, u);
		x.push_back(anc);
		y.push_back(pr);
		y2.push_back(v);
	};
	trav(i, cs) trav(j, gr[i])
		if(!count(all(cs), j))
			fun(i, j);

	cout << sz(x) << endl;
	rep(i,0,sz(x))
		cout << x[i]+1 << ' ' << y[i]+1 << ' ' << y2[i]+1 << endl;
}