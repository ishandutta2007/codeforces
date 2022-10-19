#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const ll INF=1e18+7, LIM=607;
vector<pair<int,ll>>V[LIM];
vector<int>M[LIM];
ll odl[LIM][LIM], T[LIM], mt[LIM], sk[LIM], odw[LIM], v, n, k;
bool DFS(int x) {
	if(odw[x]) return false;
	odw[x]=1;
	for(auto i : M[x]) if(mt[i]==-1 || DFS(mt[i])) {
		mt[i]=x;
		return true;
	}
	return false;
}
bool f(int x) {
	rep(i, n) {
		M[i].clear();
		rep(j, v) if(odl[T[i]][j]<=x) M[i].pb(j);
		random_shuffle(all(M[i]));
	}
	rep(i, v) mt[i]=-1;
	rep(i, n) sk[i]=0;
	int ans=0;
	bool ok=true;
	while(ok) {
		ok=false;
		rep(i, n) odw[i]=0;
		rep(i, n) if(!sk[i] && DFS(i)) {
			sk[i]=1;
			++ans;
			ok=true;
		}
	}
	return ans>=k;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int e;
	cin >> v >> e >> n >> k;
	rep(i, n) {
		cin >> T[i]; --T[i];
	}
	while(e--) {
		int a, b, c;
		cin >> a >> b >> c; --a; --b;
		V[a].pb({b, c});
		V[b].pb({a, c});
	}
	rep(i, v) {
		rep(j, v) odl[i][j]=INF;
		priority_queue<pair<ll,ll>>q;
		q.push({0, i});
		while(!q.empty()) {
			ll o=-q.top().st, p=q.top().nd; q.pop();
			if(odl[i][p]<=o) continue;
			odl[i][p]=o;
			for(auto j : V[p]) if(odl[i][j.st]==INF) q.push({-o-j.nd, j.st});
		}
	}
	int po=0, ko=20000000;
	while(po<ko) {
		int sr=(po+ko)/2;
		if(f(sr)) ko=sr; else po=sr+1;
	}
	cout << (po>1731311?-1:po) << '\n';
}