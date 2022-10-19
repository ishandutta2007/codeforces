#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,sz[500100],num[500100],mx,cnt[500100];
ll sum[500100],res;
vector<int>v[500100];
bool cheodd(int x,int y){return min(sz[x],sz[y])&1;}
void dfs1(int x,int fa){sz[x]=1;for(auto y:v[x])if(y!=fa)dfs1(y,x),sz[x]+=sz[y];}
void dfs2(int x,int fa){
	sum[x]=cnt[x]=0;
	for(auto y:v[x])if(y!=fa){
		dfs2(y,x);
		if(cheodd(x,y))res+=(sum[y]+=++cnt[y]),sum[x]+=sum[y],cnt[x]+=cnt[y];
	}
	for(auto y:v[x])if(y!=fa){
		if(cheodd(x,y))continue;
		res+=sum[x]*cnt[y]+sum[y]*cnt[x];	
	}
	if(fa&&cheodd(x,fa))for(auto y:v[x])if(y!=fa){
		if(cheodd(x,y))continue;
		sum[x]+=sum[y],cnt[x]+=cnt[y];	
	}
}
bool tri[500100];
int X,Y;
void dfs3(int x,int fa){
	if(num[x]==3)tri[x]=true;
	int tot=0;
	for(auto y:v[x])if(y!=fa)dfs3(y,x),tot+=tri[y],tri[x]|=tri[y];
	if(num[x]==3&&(!tot||(!fa&&tot==1))){
		if(!X)X=x;
		else if(!Y)Y=x;
		else{puts("0");exit(0);}
	}
}
int dfs4(int x,int st,int fa){
	if(x==st)return 0;
	for(auto y:v[x])if(y!=fa){
		int tmp=dfs4(y,st,x);
		if(tmp!=-1)return tmp+cheodd(y,x);
	}
	return -1;
}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
	if(n&1){puts("0");return 0;}
	dfs1(1,0);
	for(int i=1;i<=n;i++)for(auto j:v[i])if(cheodd(i,j))num[i]++;
	for(int i=1;i<=n;i++)mx=max(mx,num[i]);
	if(mx>3){puts("0");return 0;}
	if(mx==1){
		for(int i=2;i<=n;i++)if(!(sz[i]&1))res+=1ll*sz[i]*(n-sz[i]);
		dfs2(1,0);
	}else{
		for(int i=1;i<=n;i++)if(num[i]==3){dfs3(i,0);break;}
		if(!Y){
			dfs2(X,0),res=0;
			vector<ll>u;
			for(auto y:v[X])if(cheodd(y,X))u.push_back(y);
			assert(u.size()==3);
			for(auto i:u)for(auto j:u)if(i!=j)res+=sum[i]*cnt[j];
		}else{
//			printf("%d %d\n",X,Y);
			vector<int>ux,uy;
			int fx,fy;
			dfs1(X,0);for(auto x:v[Y])if(sz[x]>sz[Y])fy=x;
			dfs1(Y,0);for(auto y:v[X])if(sz[y]>sz[X])fx=y;
			dfs2(X,fx);for(auto y:v[X])if(y!=fx&&cheodd(y,X))ux.push_back(y);
			dfs2(Y,fy);for(auto x:v[Y])if(x!=fy&&cheodd(x,Y))uy.push_back(x);
//			for(auto i:ux)printf("%d:%d,%d\n",i,sum[i],cnt[i]);puts("");
//			for(auto i:uy)printf("%d:%d,%d\n",i,sum[i],cnt[i]);puts("");
			res=0;
			ll tot=0;
			for(auto i:ux)for(auto j:uy)res+=sum[i]*cnt[j]+sum[j]*cnt[i],tot+=1ll*cnt[i]*cnt[j];
			int tmp=dfs4(X,Y,0);
			res+=tot*tmp;
		}
	}
	printf("%lld\n",res);
	return 0;
}
/*
6
1 2
1 3
1 4
4 5
4 6
*/