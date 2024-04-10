#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
const ll INF=1e18+7;
const int LIM=1e5+7, LG=20;
vector<int>P;
vector<pair<int,ll>>V[LIM], G[LIM];
int F[LIM], pre[LIM], post[LIM], nxt[LIM][LG], lpre, lpost;
ll dist[LIM][50], odl[LIM];
int fnd(int x) {
	if(F[x]==x) return x;
	return F[x]=fnd(F[x]);
}
bool uni(int a, int b) {
	if(fnd(a)==fnd(b)) return false;
	F[fnd(b)]=fnd(a);
	return true;
}
void DFS(int x, int o) {
	pre[x]=lpre; ++lpre;
	for(auto i : G[x]) if(i.st!=o) {
		nxt[i.st][0]=x;
		odl[i.st]=odl[x]+i.nd;
		DFS(i.st, x);
	}
	post[x]=lpost; ++lpost;
}
bool oc(int a, int b) {
	return pre[a]<=pre[b] && post[a]>=post[b];
}
int lca(int a, int b) {
	if(oc(a, b)) return a;
	for(int i=LG-1; i>=0; --i) if(!oc(nxt[a][i], b)) a=nxt[a][i];
	return nxt[a][0];
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	rep(i, n) F[i]=i;
	while(m--) {
		int a, b, c;
		cin >> a >> b >> c; --a; --b;
		V[a].pb({b, c});
		V[b].pb({a, c});
		if(uni(a, b)) {
			G[a].pb({b, c});
			G[b].pb({a, c});
		} else {
			P.pb(a);
			P.pb(b);
		}
	}
	rep(i, P.size()) {
		rep(j, n) dist[j][i]=INF;
		priority_queue<pair<ll,ll>>q;
		q.push({0, P[i]});
		while(!q.empty()) {
			ll o=-q.top().st, p=q.top().nd; q.pop();
			if(dist[p][i]<=o) continue;
			dist[p][i]=o;
			for(auto j : V[p]) if(dist[j.st][i]==INF) q.push({-o-j.nd, j.st});
		}
	}
	DFS(0, 0);
	for(int j=1; j<LG; ++j) {
		rep(i, n) nxt[i][j]=nxt[nxt[i][j-1]][j-1];
	}
	int q;
	cin >> q;
	while(q--) {
		int a, b;
		cin >> a >> b; --a; --b;
		ll ans=odl[a]+odl[b]-2*odl[lca(a, b)];
		rep(i, P.size()) ans=min(ans, dist[a][i]+dist[b][i]);
		cout << ans << '\n';
	}
}