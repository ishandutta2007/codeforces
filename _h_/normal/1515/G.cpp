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

vi val, comp, z, cont;
int Time, ncomps;
template<class G, class F> int dfs(int j, G& g, F& f) {
	int low = val[j] = ++Time, x; z.push_back(j);
	for (auto e : g[j]) if (comp[e] < 0)
		low = min(low, val[e] ?: dfs(e,g,f));

	if (low == val[j]) {
		do {
			x = z.back(); z.pop_back();
			comp[x] = ncomps;
			cont.push_back(x);
		} while (x != j);
		f(cont); cont.clear();
		ncomps++;
	}
	return val[j] = low;
}
template<class G, class F> void scc(G& g, F f) {
	int n = sz(g);
	val.assign(n, 0); comp.assign(n, -1);
	Time = ncomps = 0;
	rep(i,0,n) if (comp[i] < 0) dfs(i, g, f);
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n, m;
	cin >> n >> m;

	vector<vi> gr(n), ls(n);
	rep(_,0,m){
		int a, b, l;
		cin >> a >> b >> l;
		--a, --b;
		gr[a].push_back(b);
		ls[a].push_back(l);
	}
	scc(gr,[&](vi &v){return;});
	vector<ll> gc(ncomps, 0), dist(n, -1);
	rep(i,0,n) if(dist[i] == -1){
		stack<int> st;
		dist[i] = 0;
		st.push(i);
		while(!st.empty()){
			int j = st.top();
			st.pop();
			rep(ix,0,sz(gr[j])){
				int k = gr[j][ix];
				if(comp[k] == comp[j] && dist[k] == -1){
					dist[k] = dist[j] + ls[j][ix];
					st.push(k);
				}
			}
		}
	}
	rep(i,0,n) rep(ix,0,sz(gr[i])) if(comp[i] == comp[gr[i][ix]]){
		ll dif = dist[gr[i][ix]] - (dist[i] + ls[i][ix]);
		gc[comp[i]] = __gcd(gc[comp[i]], abs(dif));
	}
	int q;
	cin >> q;
	rep(_,0,q){
		int v, s, t;
		cin >> v >> s >> t;		
		--v;
		ll g = gc[comp[v]];
		if(s % __gcd(g, (ll)t) == 0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}