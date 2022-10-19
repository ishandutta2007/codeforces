#include<bits/stdc++.h>
using namespace std;
int n,p[200100],q[200100];
bool col[200100];
vector<pair<int,int> >v;
void SWAP(int x,int y){v.emplace_back(x,y),swap(p[x],p[y]),col[p[x]]^=1,col[p[y]]^=1,q[p[x]]=x,q[p[y]]=y;}
vector<int>u;
bool vis[200100];
void decomp(int x,int y){
//	printf("%d %d\n",x,y);
	while(p[x]!=y){
		vis[x]=false;
		int tx=p[x];
		SWAP(q[x],x);
		x=tx;
	}
	while(p[y]!=x){
		vis[y]=false;
		int ty=p[y];
		SWAP(q[y],y);
		y=ty;
	}
	SWAP(x,y),vis[x]=vis[y]=false;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]),q[p[i]]=i;
	for(int i=1;i<=n;i++){
		if(vis[i]||p[i]==i)continue;
		for(int j=p[i];;j=p[j]){vis[j]=true;if(j==i)break;}
		u.push_back(i);
	}
	while(u.size()>=2){
		int x=u.back();u.pop_back();
		int y=u.back();u.pop_back();
		SWAP(x,y);
		decomp(p[x],p[y]);
	}
	if(!u.empty()){
		int x=u.back();
		for(int i=1;i<=n;i++)if(!vis[i]){SWAP(i,x),decomp(p[i],p[x]),x=-1;break;}
		if(x!=-1){
			int y=p[x];
			SWAP(x,y);
			int z=p[x];
			SWAP(z,y);
//			for(int i=1;i<=n;i++)printf("%d ",p[i]);puts("");
//			for(int i=1;i<=n;i++)printf("%d ",col[i]);puts("");
			decomp(p[x],p[y]);
		}
	}
//	for(int i=1;i<=n;i++)printf("%d ",p[i]);puts("");
//	for(int i=1;i<=n;i++)printf("%d ",col[i]);puts("");
	printf("%d\n",v.size());
	for(auto x:v)printf("%d %d\n",x.first,x.second);
	return 0;
}