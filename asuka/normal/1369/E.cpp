#include<bits/stdc++.h>
#define ll long long
#define N 200015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
int n,m,w[N];
vector<pii> e[N];
queue<int> q;
VI ans;
bool vis[N];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d",&n,&m);
	rep(i,1,n) scanf("%d",&w[i]);
	rep(i,1,m){
		int u,v; scanf("%d%d",&u,&v);
		e[u].pb(mp(v,i)); e[v].pb(mp(u,i));
		w[u]--; w[v]--;
	}
	rep(i,1,n) if(w[i] >= 0) q.push(i);
	while(!q.empty()){
		int u = q.front(); q.pop();
		for(auto V:e[u]){
			int v = V.fi,id = V.se;
			if(vis[id]) continue;
			vis[id] = 1;
			ans.pb(id);
			if(++w[v] == 0) q.push(v);
		}
	}
	if(ans.size() < m) return puts("DEAD"),0;
	puts("ALIVE");
	reverse(all(ans));
	for(auto u:ans) printf("%d ",u);
	return 0;
}