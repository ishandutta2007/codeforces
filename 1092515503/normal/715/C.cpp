#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,head[100100],cnt,ten[100100],net[100100];
ll res,ans;
struct node{int to,next,val;}edge[200100];
void ae(int u,int v,int w){
	edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].val=w,head[u]=cnt++;
	edge[cnt].next=head[v],edge[cnt].to=u,edge[cnt].val=w,head[v]=cnt++;
}
int dep[100100],sz[100100],msz[100100],RT,SZ,fr[100100],to[100100];
bool vis[100100];
void getroot(int x,int fa){
	sz[x]=1,msz[x]=0;
	for(int i=head[x],y;i!=-1;i=edge[i].next)if((y=edge[i].to)!=fa&&!vis[y])getroot(y,x),sz[x]+=sz[y],msz[x]=max(msz[x],sz[y]);
	msz[x]=max(msz[x],SZ-sz[x]);
	if(msz[x]<msz[RT])RT=x;
}
void getsz(int x,int fa){sz[x]=1;for(int i=head[x],y;i!=-1;i=edge[i].next)if((y=edge[i].to)!=fa&&!vis[y])getsz(y,x),sz[x]+=sz[y];}
void getmodulo(int x,int fa){
	for(int i=head[x],y;i!=-1;i=edge[i].next)if((y=edge[i].to)!=fa&&!vis[y]){
		dep[y]=dep[x]+1;
		fr[y]=(fr[x]+1ll*ten[dep[x]]*edge[i].val)%m;
		to[y]=(10ll*to[x]+edge[i].val)%m;
		getmodulo(y,x);
	}
}
map<int,int>mp;
void getwrite(int x,int fa){mp[fr[x]]++;for(int i=head[x],y;i!=-1;i=edge[i].next)if((y=edge[i].to)!=fa&&!vis[y])getwrite(y,x);}
void getread(int x,int fa){
	int tmp=(m-1ll*to[x]*net[dep[x]]%m)%m;if(mp.find(tmp)!=mp.end())ans+=mp[tmp];
	for(int i=head[x],y;i!=-1;i=edge[i].next)if((y=edge[i].to)!=fa&&!vis[y])getread(y,x);
}
void getans(int x){
	fr[x]=to[x]=dep[x]=0,getmodulo(x,0);
	mp.clear(),ans=0,getwrite(x,0),getread(x,0),res+=ans;
	for(int i=head[x],y;i!=-1;i=edge[i].next)if(!vis[y=edge[i].to])mp.clear(),ans=0,getwrite(y,x),getread(y,x),res-=ans;
}
void solve(int x){
	getsz(x,0),getans(x),vis[x]=true;
	for(int i=head[x],y;i!=-1;i=edge[i].next)if(!vis[y=edge[i].to])RT=0,SZ=sz[edge[i].to],getroot(y,x),solve(RT);
}
void exgcd(int a,int b,int&x,int&y){
	if(!b){x=1,y=0;return;}
	exgcd(b,a%b,y,x),y-=a/b*x;
}
void init(){
	int x,y;exgcd(10,m,x,y);
	x%=m;if(x<m)x+=m;
	ten[0]=1;for(int i=1;i<=n;i++)ten[i]=10ll*ten[i-1]%m;
	net[0]=1;for(int i=1;i<=n;i++)net[i]=1ll*net[i-1]*x%m;
}
int main(){
	scanf("%d%d",&n,&m),memset(head,-1,sizeof(head)),init();
	for(int i=1,x,y,z;i<n;i++)scanf("%d%d%d",&x,&y,&z),x++,y++,ae(x,y,z);
	msz[0]=n,SZ=n,getroot(1,0),solve(RT);
	printf("%lld\n",res-n);
	return 0;
}