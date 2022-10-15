#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define f first
#define s second
#define MX(a,b) a = max(a,b)

#define bug(x) cerr<<#x<<" is "<<x<<endl
#define ALL(x) x.begin(),x.end()
#define FOR(i,a,b) for (int i = (a); i<(b); i++)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define SZ(x) (int)x.size()
#ifndef LOCAL
#define endl '\n'
#endif
#define int ll	

using namespace std;

const int maxn = 1e6+2;
int ho[maxn], vo[maxn];
//vector<int> hh, vv;
vector<pii> at[maxn];
vector<ll> g[maxn];
map<int, int> mp;

struct DSU{
	vector<int> par;
	int find(int x){
		if (par[x] == x) return x;
		return par[x] = find(par[x]);
	}
	void merge(int a, int b){
		par[find(b)] = find(a);
	}
	DSU (int n){
		par.resize(n);
		REP(i,n) par[i] = i;
	}
};

int mv[maxn];

signed main(){
	ios::sync_with_stdio(false), cin.tie(0);
	int n, m; cin>>n>>m;
	vector<int> vals;
	REP(i,n){
		g[i].resize(m);
		REP(j,m) {
			cin>>g[i][j]; vals.pb(g[i][j]);
		}
	}
	sort(ALL(vals));
	int id = 1;
	REP(i, SZ(vals)){
		if (i==0 || vals[i] != vals[i-1]) {
			id++;
		} mp[vals[i]] = id;
	}
	REP(i,n) REP(j,m){
		g[i][j] = mp[g[i][j]];
		at[g[i][j]].pb({i,j});
	}
//	int nat = 1;
	DSU dd (m+2);
	FOR(v,1,id+1){
//		bool b = 0;

		sort(ALL(at[v]));
		int N = SZ(at[v]);
		REP(i,N){
			if (i && at[v][i].f == at[v][i-1].f) {
				dd.merge(at[v][i].s, at[v][i-1].s);
			}
		}
		for (pii &d : at[v]){
			int f = dd.find(d.s);
			MX(mv[f], max(ho[d.f], vo[d.s]));
		}
		
		for (pii &d: at[v]) { 
			int mm = mv[dd.find(d.s)]+1;
			MX(ho[d.f] , mm);
			MX(vo[d.s] , mm);
			g[d.f][d.s] = mm;
		}
		for (pii &d : at[v]){
			mv[dd.find(d.s)] = 0;
		}
		for (pii &d : at[v]){
			dd.par[d.s] = d.s;
		}
	}
	REP(i,n) REP(j,m){
		cout<<g[i][j]<<" \n"[j==m-1];
	}
}