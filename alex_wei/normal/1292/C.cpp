#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=3e3+5;
vector <ll> e[N];
ll n,f[N][N],father[N],sz[N],ck[N][N];
struct se{ll u,fu,v,fv;};
void dfs(ll nd){
	sz[nd]=1;
	for(int i=0;i<e[nd].size();i++){
		int j=e[nd][i];
		if(j!=father[nd])father[j]=nd,dfs(j),sz[nd]+=sz[j];
	}
}
ll calc(ll nd,ll nd2){
	if(father[nd]==nd2)return sz[nd];
	else return n-sz[nd2];
}
queue <se> q;
void push(ll x,ll fx,ll y,ll fy){
	if(ck[x][y])return;
	ck[x][y]=ck[y][x]=1;
	q.push((se){x,fx,y,fy});
};
signed main(){
	cin>>n;
	for(ll i=1;i<n;++i){
		ll u,v; cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
		push(u,v,v,u);
	}
	dfs(1);
	for(ll nd=1;nd<=n;++nd)
		for(int l=0;l<e[nd].size();l++){
			int nd2=e[nd][l];
			if(nd<nd2)
				f[nd][nd2]=f[nd2][nd]=calc(nd,nd2)*calc(nd2,nd);
		}
	ll ans=0;
	while(q.size()){
		ll u=q.front().u,fu=q.front().fu,v=q.front().v,fv=q.front().fv; q.pop();
		for(int i=0;i<e[u].size();i++){
			int x=e[u][i];
			if(x!=fu){
				f[v][x]=f[x][v]=max(f[x][v],f[u][v]+calc(v,fv)*calc(x,u));
				push(x,u,v,fv);
			}
		}
		for(int i=0;i<e[v].size();i++){
			int x=e[v][i];
			if(x!=fv){
				f[x][u]=f[u][x]=max(f[x][u],f[u][v]+calc(u,fu)*calc(x,v));
				push(x,v,u,fu);
			}
		}
	}
	for(ll i=1;i<=n;++i)
		for(ll j=1;j<=n;++j)
			ans=max(ans,f[i][j]);
	cout<<ans<<endl;
	return 0;
}