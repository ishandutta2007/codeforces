#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
const int LIM=2e5+7, LG=20;
vector<pair<int,ll>>V[LIM];
pair<ll,pair<int,int>>kraw[LIM], kraw2[LIM];
int F[LIM], pre[LIM], post[LIM], nxt[LIM][LG], ma[LIM][LG], lpre, lpost;
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
	++lpre;
	pre[x]=lpre;
	for(auto i : V[x]) if(i.st!=o) {
		nxt[i.st][0]=x;
		ma[i.st][0]=i.nd;
		DFS(i.st, x);
	}
	++lpost;
	post[x]=lpost;
}
bool oc(int a, int b) {
	return pre[a]<=pre[b] && post[a]>=post[b];
}
int lca(int a, int b) {
	int ans=0;
	if(!oc(a, b)) {
		for(int i=LG-1; i>=0; --i) if(!oc(nxt[a][i], b)) {
			ans=max(ans, ma[a][i]);
			a=nxt[a][i];
		}
		ans=max(ans, ma[a][0]);
		a=nxt[a][0];
	}
	if(!oc(b, a)) {
		for(int i=LG-1; i>=0; --i) if(!oc(nxt[b][i], a)) {
			ans=max(ans, ma[b][i]);
			b=nxt[b][i];
		}
		ans=max(ans, ma[b][0]);
	}
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	rep(i, n) F[i]=i;
	rep(i, m) {
		cin >> kraw[i].nd.st >> kraw[i].nd.nd >> kraw[i].st;
		--kraw[i].nd.st; --kraw[i].nd.nd;
		kraw2[i]=kraw[i];
	}
	sort(kraw, kraw+m);
	ll sum=0;
	rep(i, m) {
		if(uni(kraw[i].nd.st, kraw[i].nd.nd)) {
			sum+=kraw[i].st;
			V[kraw[i].nd.st].pb({kraw[i].nd.nd, kraw[i].st});
			V[kraw[i].nd.nd].pb({kraw[i].nd.st, kraw[i].st});
		}
	}
	DFS(0, 0);
	for(int j=1; j<LG; ++j) {
		rep(i, n) {
			nxt[i][j]=nxt[nxt[i][j-1]][j-1];
			ma[i][j]=max(ma[i][j-1], ma[nxt[i][j-1]][j-1]);
		}
	}
	rep(i, m) {
		cout << sum+kraw2[i].st-lca(kraw2[i].nd.st, kraw2[i].nd.nd) << '\n';
	}
}