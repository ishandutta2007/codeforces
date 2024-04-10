#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,mod,bs,tar,pov[100100],inv[100100],a[100100];
int ksm(int x,int y=mod-2){int z=1;for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)z=1ll*z*x%mod;return z;}
vector<int>v[100100];
int RT,SZ,sz[100100],msz[100100],dep[100100],in[100100],out[100100],IN[100100],OUT[100100];
bool vis[100100];
void getroot(int x,int fa){
	sz[x]=1,msz[x]=0;
	for(auto y:v[x])if(y!=fa&&!vis[y])getroot(y,x),sz[x]+=sz[y],msz[x]=max(msz[x],sz[y]);
	msz[x]=max(msz[x],SZ-sz[x]);if(msz[RT]>msz[x])RT=x;
}
void getsz(int x,int fa){sz[x]=1;for(auto y:v[x])if(y!=fa&&!vis[y])getsz(y,x),sz[x]+=sz[y];}
void getmodulo(int x,int fa){
	for(auto y:v[x])if(y!=fa&&!vis[y])dep[y]=dep[x]+1,out[y]=(1ll*out[x]*bs+a[y])%mod,in[y]=(1ll*pov[dep[x]-1]*a[y]+in[x])%mod,getmodulo(y,x);
//	printf("%d,%d:%d,%d\n",x,dep[x],in[x],out[x]);
	out[x]=1ll*(tar+mod-out[x])*inv[dep[x]]%mod;
//	printf("%d,%d:%d,%d\n",x,dep[x],in[x],out[x]);
}
map<int,int>mi,mo;
void getwrite(int x,int fa){
	mi[in[x]]++,mo[out[x]]++;
	for(auto y:v[x])if(y!=fa&&!vis[y])getwrite(y,x);
}
void getread(int x,int fa,int tp){
	if(mo.find(in[x])!=mo.end())IN[x]+=tp*mo[in[x]];
	if(mi.find(out[x])!=mi.end())OUT[x]+=tp*mi[out[x]];
	for(auto y:v[x])if(y!=fa&&!vis[y])getread(y,x,tp);
}
void getans(int x){
//	printf("%d:\n",x);
	out[x]=a[x],in[x]=0,dep[x]=1,getmodulo(x,0);
	mi.clear(),mo.clear(),getwrite(x,0),getread(x,0,1);
	for(auto y:v[x])if(!vis[y])mi.clear(),mo.clear(),getwrite(y,x),getread(y,x,-1);
}
void solve(int x){
	getsz(x,0),getans(x),vis[x]=true;
	for(auto y:v[x])if(!vis[y])SZ=sz[y],RT=0,getroot(y,x),solve(RT);
}
ll res;
int main(){
	scanf("%d%d%d%d",&n,&mod,&bs,&tar);
	pov[0]=1;for(int i=1;i<=n;i++)pov[i]=1ll*pov[i-1]*bs%mod;
	inv[n]=ksm(pov[n]);for(int i=n;i;i--)inv[i-1]=1ll*inv[i]*bs%mod;
//	for(int i=0;i<=n;i++)printf("%d ",pov[i]);puts(""); 
//	for(int i=0;i<=n;i++)printf("%d ",inv[i]);puts(""); 
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
	msz[RT=0]=SZ=n,getroot(1,0),solve(RT);
//	for(int i=1;i<=n;i++)printf("%d %d\n",IN[i],OUT[i]);
	for(int i=1;i<=n;i++)res+=2ll*IN[i]*(n-IN[i])+2ll*OUT[i]*(n-OUT[i])+1ll*IN[i]*(n-OUT[i])+1ll*(n-IN[i])*OUT[i];
	printf("%lld\n",1ll*n*n*n-res/2);
	return 0;
}