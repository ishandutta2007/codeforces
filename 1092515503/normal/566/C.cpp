#include<bits/stdc++.h>
using namespace std;
int n,a[200100],head[200100],cnt,sz[200100],msz[200100],RT,SZ,dep[200100];
struct node{int to,next,val;}edge[400100];
void ae(int u,int v,int w){
	edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].val=w,head[u]=cnt++;
	edge[cnt].next=head[v],edge[cnt].to=u,edge[cnt].val=w,head[v]=cnt++;
}
bool vis[200100];
#define forhead for(int i=head[x],y;i!=-1;i=edge[i].next)if(!vis[y=edge[i].to])
void getroot(int x,int fa){
	sz[x]=1,msz[x]=0;
	forhead if(y!=fa)getroot(y,x),sz[x]+=sz[y],msz[x]=max(msz[x],sz[y]);
	msz[x]=max(msz[x],SZ-sz[x]);
	if(msz[x]<msz[RT])RT=x;
}
void getsz(int x,int fa){sz[x]=1;forhead if(y!=fa)getsz(y,x),sz[x]+=sz[y];}
double deri[200100],res,mn=0x3f3f3f3f3f3f3f3f;int rp;
void getdep(int x,int fa){
	res+=a[x]*pow(dep[x],1.5);
	deri[x]=1.5*a[x]*sqrt(dep[x]);
	for(int i=head[x],y;i!=-1;i=edge[i].next)if((y=edge[i].to)!=fa)
		dep[y]=dep[x]+edge[i].val,getdep(y,x),deri[x]+=deri[y];
}
int getans(int x){
	res=0,dep[x]=0,getdep(x,0);
	if(mn>res)mn=res,rp=x;
	forhead if(deri[x]<deri[y]*2)return y;
	return x;
}
void solve(int x){
	int y=getans(x);
	if(x==y)return;
	vis[x]=true,getsz(x,0),RT=0,SZ=sz[y],getroot(y,0),solve(RT);
}
int main(){
	scanf("%d",&n),memset(head,-1,sizeof(head));
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1,x,y,z;i<n;i++)scanf("%d%d%d",&x,&y,&z),ae(x,y,z);
	SZ=msz[RT=0]=n,getroot(1,0),solve(RT);
	printf("%d %lf\n",rp,mn);
	return 0;
}