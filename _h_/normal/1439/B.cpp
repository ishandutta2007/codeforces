#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef unsigned long long ull;
typedef vector<ull> vull;

void flp(vull &ls, int i){
	ls[i>>6] ^= ull(1) << (i & 63);
}

bool sub(vull &l1, vull &l2){
	rep(i,0,sz(l1)) if( l1[i] & (~l2[i]) ) return false;
	return true;
}

void solve(){
	int n, m, k;
	cin >> n >> m >> k;

	vector<vi> gr(n);
	rep(_,0,m){
		int u, v;
		cin >> u >> v;
		--u, --v;
		gr[u].push_back(v);
		gr[v].push_back(u);
	}
	vi deg(n);
	rep(i,0,n) deg[i] = sz(gr[i]);
	stack<int> st;
	rep(i,0,n) if(deg[i] < k-1){
		st.push(i);
	}
	while(!st.empty()){
		int v = st.top(); st.pop();
		trav(u, gr[v]) if(deg[u] >= k-1){
			--deg[u];
			if(deg[u] < k-1){
				st.push(u);
			}
		}
	}
	if(k <= 50){
		vector<set<int>> gs(n);	
		rep(i,0,n) if(deg[i] >= k-1) trav(j, gr[i]) if(deg[j] >= k-1){
			gs[i].insert(j);
		}
		stack<int> ko;
		rep(i,0,n) if(sz(gs[i]) == k-1) ko.push(i);
		while(!ko.empty()){
			int v = ko.top(); ko.pop();
			vi mygr(k-1);
			int ix = 0;
			if(sz(gs[v]) < k-1) goto foo;
			trav(u, gs[v]) mygr[ix++] = u;
			rep(i,0,k-1) rep(j,0,i)
				if(!gs[mygr[i]].count(mygr[j])){
				goto foo;
			}
			cout << 2 << endl;
			cout << v+1;
			trav(u, mygr) cout << " " << u+1;
			cout << endl << endl;
			return;
			foo: ;
			trav(u, gs[v]){
				gs[u].erase(v);
				if(sz(gs[u]) == k-1) ko.push(u);
			}
			gs[v].clear();
		}
		vi ans;
		rep(i,0,n) if(sz(gs[i]) >= k) ans.push_back(i);
		if(ans.empty()){
			cout << -1 << endl << endl;
		} else {
			cout << 1 << " " << sz(ans) << endl;
			trav(u, ans) cout << u+1 << " ";
			cout << endl << endl;
		}
	} else {
		vi ren;
		rep(i,0,n) if(deg[i] >= k-1) ren.push_back(i);
		int N = sz(ren);
		vector<vull> gs(N, vull(N / 64 + 1));
		vi ner(n);
		rep(i,0,N) ner[ren[i]] = i;
		vi ds(N);
		rep(i,0,N) trav(j, gr[ren[i]]) if(deg[j] >= k-1){
			flp(gs[i], ner[j]);
			++ds[i];
		}
		stack<int> ko;
		rep(i,0,N) if(ds[i] == k-1) ko.push(i);
		while(!ko.empty()){
			int i = ko.top(); ko.pop();
			vi ans = {ren[i]+1};
			if(ds[i] < k-1) goto bar;
			rep(jj, 0, sz(gs[i])) rep(t,0,64) if(gs[i][jj] & (ull(1) << t)){
				int j = (jj << 6) ^ t;
				flp(gs[j], j);
				if(!sub(gs[i], gs[j])){
					goto bar;
				}
				flp(gs[j], j);
				ans.push_back(ren[j]+1);
			}
			cout << 2 << endl;
			trav(x, ans) cout << x << " ";
			cout << endl << endl;
			return;
			bar: ;
			ds[i] = 0;
			rep(jj, 0, sz(gs[i])) rep(t,0,64) if(gs[i][jj] & (ull(1) << t)){
				int j = (jj << 6) ^ t;
				flp(gs[j], i);
				--ds[j];
				if(ds[j] == k-1) ko.push(j);
			}
		}
		vi ans;
		rep(i,0,N) if(ds[i] >= k) ans.push_back(ren[i]+1);
		if(ans.empty()){
			cout << -1 << endl << endl;
		} else {
			cout << 1 << " " << sz(ans) << endl;
			trav(u, ans) cout << u << " ";
			cout << endl << endl;
		}
	}
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	int n;
	cin >> n;

	rep(_,0,n) solve();
}