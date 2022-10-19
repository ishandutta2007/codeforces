#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define vi vector<int>
int n,cnt,t1,t2,head[400100],sz[401000],fa[400100],d1,d2,ans;
vi dia,sol;
struct node{
	int to,next;
}edge[401000];
void ae(int u,int v){
	edge[cnt].next=head[u],edge[cnt].to=v,head[u]=cnt++;
}
pii dfs(int x){//first--dis second--node
	pii p=mp(0,x);
	for(int i=head[x];i!=-1;i=edge[i].next){
		if(edge[i].to==fa[x])continue;
		fa[edge[i].to]=x;
		pii res=dfs(edge[i].to);
		res.first++,p=max(p,res);
	}
	return p;
}
pii che(int x,int pa){//first-- 0:invalid 1:normal 2:special.  second--the depth of its subtree
	int ch=sz[x]-(pa!=0);
	if(ch>3)return mp(0,-1);
	if(!ch)return mp(1,0);
	vi scp,nom;
	for(int i=head[x];i!=-1;i=edge[i].next){
		if(edge[i].to==pa)continue;
		pii res=che(edge[i].to,x);
		if(!res.first)return mp(0,-1);
		if(res.first==1)nom.pb(res.second);
		else scp.pb(res.second);
	}
	if(scp.size()>=2)return mp(0,-1);
	sort(nom.begin(),nom.end());
	if(ch==1){
		ans=x;
		if(nom.size()==1&&!nom[0])return mp(2,1);
		return mp(0,-1);
	}
	if(ch==2){
		if(nom.size()==2&&nom[0]==nom[1])return mp(1,nom[0]+1);
		if(nom.size()==1&&scp.size()==1&&nom[0]==scp[0])return mp(2,nom[0]+1);
		return mp(0,-1);
	}
	if(ch==3){
		ans=x;
		if(nom.size()==3&&nom[0]==nom[2]-1&&nom[1]==nom[2]-1)return mp(2,nom[2]+1);
		return mp(0,-1);
	}
	return mp(0,-1);
}
int main(){
	scanf("%d",&n),n=(1<<n)-2,memset(head,-1,sizeof(head));
	for(int i=1;i<n;i++)scanf("%d%d",&t1,&t2),ae(t1,t2),ae(t2,t1),sz[t1]++,sz[t2]++;
	fa[1]=-1,d1=dfs(1).second;
	fa[d1]=-1,d2=dfs(d1).second;
	fa[d2]=-1,d1=dfs(d2).second;
	while(fa[d1]!=-1)dia.pb(d1),d1=fa[d1];
	dia.pb(d1);
//	for(int i=0;i<dia.size();i++)printf("%d ",dia[i]);puts("");
	int md=(int(dia.size())>>1);
	for(int i=md-2;i<=md+2;i++){
		if(i<0||i>=dia.size())continue;
//		printf("%d\n",dia[i]);
		pii res=che(dia[i],0);
		if(res.first==2)sol.pb(ans);
	}
	sort(sol.begin(),sol.end()),sol.erase(unique(sol.begin(),sol.end()),sol.end());
	printf("%d\n",sol.size());
	for(int i=0;i<sol.size();i++)printf("%d ",sol[i]);
	return 0;
}