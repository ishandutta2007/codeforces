#include<bits/stdc++.h>
using namespace std;
int query(int x){printf("? %d\n",x),fflush(stdout),scanf("%d",&x);return x;}
int n,f[100100],res,son[100100];
vector<int>v[100100],u[100100];
bool cmp(int i,int j){return f[i]>f[j];}
void dfs1(int x,int fa){
	son[x]=x,u[x].clear(),f[x]=0;
	for(auto y:v[x])if(y!=fa)dfs1(y,x),u[x].push_back(y);
	if(u[x].empty())return;
	sort(u[x].begin(),u[x].end(),cmp);
	son[x]=son[u[x][0]];
	for(int i=0;i<u[x].size();i++)f[x]=max(f[x],i+f[u[x][i]]);
}
void dfs2(int x,int fa){
//	printf("%d:",x);
	for(int i=0,mx=0;i<u[x].size();i++){
//		printf("[%d,%d]",u[x][i],f[u[x][i]]);
		res=max(res,i+f[u[x][i]]+mx+1);
		mx=max(mx,f[u[x][i]]);
	}//puts("");
	int mx=-1,smx=-1,mxp=-1,smxp=-1;
	for(int i=0;i<u[x].size();i++){
		if(mx<f[u[x][i]]+i)smx=mx,smxp=mxp,mx=f[u[x][i]]+i,mxp=i;
		else if(smx<f[u[x][i]]+i)smx=f[u[x][i]]+i,smxp=i;
	}
	mx=max(mx,0),smx=max(smx,0);
	int tf=f[x];
	for(int i=0,y;i<u[x].size();i++)if((y=u[x][i])!=fa){
		if(i==mxp)f[x]=smx-(smxp>i);
		else f[x]=mx-(mxp>i);
		u[y].insert(lower_bound(u[y].begin(),u[y].end(),x,cmp),x);
		dfs2(y,x);
	}
	f[x]=tf;
}
int search(int x){
	for(int i=1,y;i<u[x].size();i++){
		y=query(son[u[x][i]]);
		if(y!=x)return search(y);
	}
	return x;
}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
	if(n!=1)dfs1(1,0),dfs2(1,0);
	printf("%d\n",res),fflush(stdout);
	int RT;scanf("%d",&RT);
	if(n==1){printf("! %d %d\n",1,1),fflush(stdout);return 0;}
	dfs1(RT,0);
	int a=-1,b=-1;
	for(auto x:u[RT]){
		x=query(son[x]);
		if(x!=RT)swap(a,b),a=search(x);
		if(b!=-1)break;
	}
	if(a==-1)a=RT;if(b==-1)b=RT;
	printf("! %d %d\n",a,b),fflush(stdout);
	return 0;
}