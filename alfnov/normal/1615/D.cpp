#include<bits/stdc++.h>
//#define only_one_test
using namespace std;
vector<pair<int,int>>g[200005],l[200005];
int ans[200005],fa[200005],cnt[200005];
int pr[200005],zz[200005],aa=1;
int findfather(int x){
	if(x==fa[x])return x;
	int ff=fa[x];
	int zx=findfather(ff);
	cnt[x]^=cnt[ff],fa[x]=zx;
	return zx;
}
void merg(int x,int y,int p){
	l[x].emplace_back(make_pair(y,p));
	l[y].emplace_back(make_pair(x,p));
	int fx=findfather(x),fy=findfather(y);
	if(fx==fy){
		if((cnt[x]^cnt[y])!=p)aa=0;
	}
	if(fx!=fy){
		fa[fx]=fy,cnt[fx]^=cnt[fy]^cnt[x]^cnt[y]^p;
	}
}
void dfs(int x){
	zz[x]=1;
	for(auto cu:g[x]){
		int cc=cu.first,c2=cu.second;
		if(zz[cc])continue;
		if(c2==-1)c2=cnt[x]^cnt[cc];
		ans[cc]=ans[x]^c2;
		if(!zz[cc])dfs(cc);
	}
}
int pc(int x){
	if(!x)return 0;
	return pc(x>>1)+(x&1);
}
void dfs2(int x,int la){
	for(auto cu:g[x]){
		int cc=cu.first;
		if(cc==la)continue;
		printf("%d %d %d\n",x,cc,ans[x]^ans[cc]);
		dfs2(cc,x);
	}
}
int X[200005],Y[200005],P[200005];
int main(){
	int T=1;
#ifndef only_one_test
	cin>>T;
#endif
	while(T--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;++i){
			g[i].clear();
			l[i].clear();
			fa[i]=i,cnt[i]=0,zz[i]=0,ans[i]=0;
		}
		aa=1;
		for(int i=1;i<n;++i){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			g[u].emplace_back(make_pair(v,w));
			g[v].emplace_back(make_pair(u,w));
			if(w>=0)merg(u,v,pc(w)&1);
		}
		for(int i=1;i<=m;++i){
			int x,y,p;
			scanf("%d%d%d",&x,&y,&p);
			X[i]=x,Y[i]=y,P[i]=p;
			merg(x,y,p);
		}
		for(int i=1;i<=n;++i)if(findfather(i)!=findfather(1)){
			merg(1,i,rand()&1);
		}
		for(int i=1;i<=n;++i)findfather(i);
		if(aa==0){
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		dfs(1);
		dfs2(1,0);
	}
	return 0;
}