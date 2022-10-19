#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const ll INF=1e15+7;
const int MAXC=2e5+7;
struct edge {
	ll u, v, cap, flow;
};
int cp[200007], L[107], C[107],  P[107], n, k;
vector<pair<int,pair<int,int>>>kraw;
vector<edge>T;
vector<int>V[107];
int odl[107], li[107];
bool BFS() {
	rep(i, n+2) odl[i]=-1;
	odl[n]=0;
	queue<int>q;
	q.push(n);
	while(!q.empty()) {
		int p=q.front(); q.pop();
		for(auto i : V[p]) if(odl[T[i].v]==-1 && T[i].cap-T[i].flow>0) {
			odl[T[i].v]=odl[p]+1;
			q.push(T[i].v);
		}
	}
	return odl[n+1]!=-1;
}
ll DFS(int x, ll f) {
	if(!f) return 0;
	if(x==n+1) return f;
	for(; li[x]<V[x].size(); ++li[x]) {
		int ind=V[x][li[x]], p=T[ind].v;
		if(odl[x]+1!=odl[p] || T[ind].cap-T[ind].flow<=0) continue;
		ll nf=DFS(p, min(f, T[ind].cap-T[ind].flow));
		if(!nf) continue;
		T[ind].flow+=nf;
		T[ind^1].flow-=nf;
		return nf;
	}
	return 0;
}
bool f(int x) {
	int ma=-1, jaka=-1;
	rep(i, n) if(C[i]==1 && P[i]>ma) {
		ma=P[i];
		jaka=i;
	}
	T.clear();
	rep(i, n+2) V[i].clear();
	rep(i, n) {
		T.pb({i, n+C[i]%2, 0, 0});
		T.pb({n+C[i]%2, i, 0, 0});
		V[i].pb(T.size()-2);
		V[n+C[i]%2].pb(T.size()-1);
		if(L[i]<=x && (C[i]!=1 || jaka==i)) T[T.size()-1-C[i]%2].cap=P[i];
	}
	rep(i, n) rep(j, i) if(!cp[C[i]+C[j]]) {
		int a=i, b=j;
		if(C[a]%2==1) swap(a, b);
		T.pb({a, b, INF, 0});
		T.pb({b, a, 0, 0});
		V[a].pb(T.size()-2);
		V[b].pb(T.size()-1);
	}
	ll ans=0;
	rep(i, n) if(L[i]<=x && (C[i]!=1 || jaka==i)) ans+=P[i];
	while(BFS()) {
		rep(i, n+2) li[i]=0;
		ll akt=DFS(n, INF);
		while(akt) {
			ans-=akt;
			akt=DFS(n, INF);
		}
	}
	return ans>=k;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for(int i=2; i<MAXC; ++i) {
		if(cp[i]) continue;
		for(int j=2*i; j<MAXC; j+=i) cp[j]=1;
	}
	cin >> n >> k;
	rep(i, n) cin >> P[i] >> C[i] >> L[i];
	int po=1, ko=n+1;
	while(po<ko) {
		int sr=(po+ko)/2;
		if(f(sr)) ko=sr; else po=sr+1;
	}
	if(po==n+1) po=-1;
	cout << po << '\n';
}