#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
const int LIM=1e5+7, LG=20;
vector<int>V[LIM];
int pre[LIM], post[LIM], nxt[LIM][LG], lpre, lpost, odl[LIM], ile[LIM], n;
void DFS(int x, int o) {
	++lpre;
	pre[x]=lpre;
	ile[x]=1;
	for(auto i : V[x]) if(i!=o) {
		nxt[i][0]=x;
		odl[i]=odl[x]+1;
		DFS(i, x);
		ile[x]+=ile[i];
	}
	++lpost;
	post[x]=lpost;
}
bool oc(int a, int b) {
	return pre[a]<=pre[b] && post[a]>=post[b];
}
int lca(int a, int b) {
	if(oc(a, b)) return a;
	if(oc(b, a)) return b;
	for(int i=LG-1; i>=0; --i) if(!oc(nxt[a][i], b)) a=nxt[a][i];
	return nxt[a][0];
}
int skocz(int a, int b) {
	for(int i=LG-1; i>=0; --i) if(b>=1<<i) {
		a=nxt[a][i];
		b-=1<<i;
	}
	return a;
}
int solve(int a, int b) {
	int c=lca(a, b), o=odl[a]+odl[b]-2*odl[c];
	if(o%2==1) return 0;
	if(a==b) return n;
	o/=2; --o;
	if(odl[a]==odl[b]) {
		return n-ile[skocz(a, o)]-ile[skocz(b, o)];
	} else if(odl[a]>odl[b]) {
		return ile[skocz(a, o+1)]-ile[skocz(a, o)];
	} else return ile[skocz(b, o+1)]-ile[skocz(b, o)];
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	rep(i, n-1) {
		int a, b;
		cin >> a >> b; --a; --b;
		V[a].pb(b);
		V[b].pb(a);
	}
	DFS(0, 0);
	for(int j=1; j<LG; ++j) {
		rep(i, n) nxt[i][j]=nxt[nxt[i][j-1]][j-1];
	}
	int m;
	cin >> m;
	while(m--) {
		int a, b;
		cin >> a >> b; --a; --b;
		cout << solve(a, b) << '\n';
	}
}