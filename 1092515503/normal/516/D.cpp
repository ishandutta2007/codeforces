#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,head[100100],cnt,L[100100],R[100100],tot,ord[100100],t[100100],RT;
ll f[100100];
void ADD(int x,int y){while(x<=n)t[x]+=y,x+=x&-x;}
int SUM(int x){int ret=0;while(x)ret+=t[x],x-=x&-x;return ret;}
struct node{int to,next,val;}edge[200100];
void ae(int u,int v,int w){
	edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].val=w,head[u]=cnt++;
	edge[cnt].next=head[v],edge[cnt].to=u,edge[cnt].val=w,head[v]=cnt++;
}
multiset<ll>s[100100];
#define iter for(int i=head[x],y;i!=-1;i=edge[i].next)if((y=edge[i].to)!=fa)
void dfs1(int x,int fa){s[x].insert(0);iter dfs1(y,x),s[x].insert(*s[y].rbegin()+edge[i].val);}
void dfs2(int x,int fa){
	iter{
		s[x].erase(s[x].find(*s[y].rbegin()+edge[i].val));
		ll tmp=*s[x].rbegin()+edge[i].val;
		s[x].insert(*s[y].rbegin()+edge[i].val);
		s[y].insert(tmp);
		dfs2(y,x);
	}
}
void dfs(int x,int fa){L[x]=++tot;iter dfs(y,x);R[x]=tot;}
int main(){
	scanf("%d",&n),memset(head,-1,sizeof(head));
	for(int i=1,x,y,z;i<n;i++)scanf("%d%d%d",&x,&y,&z),ae(x,y,z);
	dfs1(1,0),dfs2(1,0);
	for(int i=1;i<=n;i++)f[i]=*s[i].rbegin(),ord[i]=i;
	sort(ord+1,ord+n+1,[](int u,int v){return f[u]<f[v];});
	dfs(ord[1],0);
//	for(int i=1;i<=n;i++)printf("[%d,%d]\n",L[i],R[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		ll x;
		scanf("%lld",&x);
		int res=0;
		for(int l=1,r=1;l<=n;l++){
			while(r<=n&&f[ord[r]]<=f[ord[l]]+x)ADD(L[ord[r++]],1);
			res=max(res,SUM(R[ord[l]])-SUM(L[ord[l]]-1));
			ADD(L[ord[l]],-1);
		}
		printf("%d\n",res);
	}
	return 0;
}