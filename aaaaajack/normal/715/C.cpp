#include<bits/stdc++.h>
#define N 100100
using namespace std;
vector<int> g[N],dig[N];
bool del[N];
int sz[N],inv[N],pw[N];
int M;
long long ans=0;
map<int,int> cup[N];
bool isprm[32000];
int qp(int n){
	int r=1,x=10;
	while(n){
		if(n&1) r=1LL*x*r%M;
		n>>=1;
		x=1LL*x*x%M;
	}
	return r;
}
int build_sz(int u,int p){
	sz[u]=1;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==p||del[v]) continue;
		build_sz(v,u);
		sz[u]+=sz[v];
	}
	return sz[u];
}
void build_up(int u,int p,int pre,int dep,int st,int br){
	cup[st][pre]++;
	cup[br][pre]++;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==p||del[v]) continue;
		build_up(v,u,(pre+1LL*pw[dep]*dig[u][i])%M,dep+1,st,br);
	}
}
void cal_down(int u,int p,int pre,int dep,int st,int br){
	int goal=1LL*(M-pre)*inv[dep]%M;
	ans+=cup[st][goal]-cup[br][goal];
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==p||del[v]) continue;
		cal_down(v,u,(pre*10LL+dig[u][i])%M,dep+1,st,br);
	}
}
void sfj(int u){
	build_sz(u,-1);
	int tt=sz[u],p=-1;
	bool flag=true;
	while(flag){
		flag=false;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i];
			if(del[v]||v==p) continue;
			if(sz[v]+sz[v]>=tt){
				p=u;
				u=v;
				flag=true;
				break;
			}
		}
	}
	del[u]=true;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(del[v]) continue;
		build_up(v,u,dig[u][i]%M,1,u,v);
	}
	ans+=cup[u][0];
	cup[u][0]++;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(del[v]) continue;
		cal_down(v,u,dig[u][i]%M,1,u,v);
	}
	cup[u].clear();
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(del[v]) continue;
		cup[v].clear();
		sfj(v);
	}
}
int main(){
	memset(isprm,-1,sizeof(isprm));
	for(int i=2;i<32000;i++){
		for(int j=2;i*j<32000;j++){
			isprm[i*j]=false;
		}
	}
	int n,x,y,z,tmp,phi;
	scanf("%d%d",&n,&M);
	tmp=M;
	phi=M;
	for(int i=2;i<32000;i++){
		if(isprm[i]&&M%i==0){
			phi=phi/i*(i-1);
			while(tmp%i==0) tmp/=i;
		}
	}
	if(tmp>1) phi=phi/tmp*(tmp-1);
	for(int i=0;i<=n;i++) inv[i]=qp(phi-i%phi),pw[i]=qp(i%phi);
	for(int i=1;i<n;i++){
		scanf("%d%d%d",&x,&y,&z);
		g[x].push_back(y);
		g[y].push_back(x);
		dig[x].push_back(z);
		dig[y].push_back(z);
	}
	sfj(0);
	printf("%I64d\n",ans);
	return 0;
}