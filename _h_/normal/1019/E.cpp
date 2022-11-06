#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a; i < (b); ++i)
#define rrep(i,a,b) for(int i = b; i --> (a);)
#define all(v) v.begin(),v.end()
#define trav(x,v) for(auto &x : v)
#define sz(v) (int)(v).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> pii;
typedef vector<pii> vp;

pii sub(pii &a, pii &b){
	return pii(a.first - b.first, a.second - b.second);
}

pii add(pii &a, pii &b){
	return pii(a.first + b.first, a.second + b.second);
}

bool frown(pii a, pii b){
	if(b.first == 0) return a.first > 0 && b.second < 0;
	if(a.first == 0) return a.second > 0;
	ll r = a.second%a.first, t = b.second%b.first;
	if(r < 0) r += a.first;
	if(t < 0) t += b.first;
	ll m = (a.second-r)/a.first, n = (b.second-t)/b.first;
	if(m != n) return m > n;
	return frown(pii(t, b.first), pii(r,a.first) );
}

void hullify(vp &ps){
	sort(all(ps));

	vp nx;
	trav(p, ps){
		while(sz(nx) >= 2){
			int i = sz(nx)-2;
			if(!frown( sub(nx[i+1],nx[i]), sub(p,nx[i]) ))
				nx.pop_back();
			else break;
		}
		nx.push_back(p);
	}
	ps = nx;
}

void sum(vp &a, vp &b, vp &res){
	for(int i = 0, j = 0;;){
		res.push_back( add(a[i], b[j]) );			

		if(i+1 < sz(a) && j+1 < sz(b)){
			if(frown( sub(a[i+1],a[i]), sub(b[j+1],b[j]) )) ++i;
			else ++j;
		} else if(i+1 == sz(a) && j+1 < sz(b)){
			++j;
		} else if(i+1 < sz(a) && j+1 == sz(b)){
			++i;
		} else {
			return;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;

	vector<vi> gr(n);
	vector<vp> ab(n);

	rep(_,1,n){
		int u, v, a, b;
		cin >> u >> v >> a >> b;
		--u, --v;
		gr[u].push_back(v);
		gr[v].push_back(u);
		ab[u].emplace_back(a,b);
		ab[v].emplace_back(a,b);
	}

	vp ps(1, pii(0,0) );

	vi par(n), ss(n);

	function<void(int, vi&)> dfs = [&](int v, vi &ls){
		ls.push_back(v);
		ss[v] = 1;
		rep(i,0,sz(gr[v])){
			int u = gr[v][i];
			if(u == par[v]) continue;
			par[u] = v;
			dfs(u, ls);
			ss[v] += ss[u];
		}
	};

	function<void(int, int, pii, vp&)>  dfs2 = [&](int v, int par, pii d, vp &ds){
		bool lf = true;
		rep(i,0,sz(gr[v])){
			int u = gr[v][i];
			if(u == par) continue;
			lf = false;
			dfs2(u, v, add(d, ab[v][i]), ds);
		}
		if(lf) ds.push_back(d);
	};

	stack<int> st;
	auto f = [&](int v0){

		vi ls;
		par[v0] = -1;
		dfs(v0, ls);

		int c = -1;
		trav(i, ls){
			trav(j, gr[i]){
				int s;
				if(j == par[i]) s = sz(ls) - ss[i];
				else s = ss[j];
				if(2*s > sz(ls)) goto nope;
			}
			c = i;
			nope:;
		}
		
		vector<vp> dl;

		rep(i,0,sz(gr[c])){
			int v = gr[c][i];
			vp ds;
			dfs2(v, c, ab[c][i], ds);
			rep(j,0,sz(gr[v])) if(gr[v][j] == c){
				gr[v].erase(gr[v].begin()+j);
				ab[v].erase(ab[v].begin()+j);
				break;
			}
			hullify(ds);
			dl.push_back(ds);

			st.push(v);
		}
		if(sz(dl) == 0) return;
		if(sz(dl) == 1){
			trav(ds, dl) trav(p, ds) ps.push_back(p);
			return;
		}

		priority_queue<pii> pq;
		rep(i,0,sz(dl)) pq.push(pii(-sz(dl[i]), i));

		while(sz(pq) >= 2){
			int i = pq.top().second;
			pq.pop();
			int j = pq.top().second;
			pq.pop();

			sum(dl[i], dl[j], ps);
			trav(p, dl[i]) dl[j].push_back(p);
			dl[i].clear();
			hullify(dl[j]);
			pq.push(pii(-sz(dl[j]), j));
		}
	};
	st.push(0);
	while(!st.empty()){
		int v0 = st.top();
		st.pop();
		f(v0);
	}

	hullify(ps);

	auto val = [&](int j, int t){
		return ps[j].first*t + ps[j].second;
	};

	int j = 0;
	rep(t,0,m){
		while(j+1 < sz(ps) && val(j, t) < val(j+1, t)) ++j;
		cout << val(j, t) << ' ';
	}
	cout << endl;
}