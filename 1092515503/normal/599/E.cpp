#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,p,f[15][1<<15];
bool g[15][15];
pair<int,int>e[15];
pair<pair<int,int>,int>l[110];
bool in(int x,int y){return x&(1<<y);}
int dfs(int x,int U){
	int &res=f[x][U],pos=0;
//	printf("%d,%d:%d\n",x,U,res);
	if(~res)return f[x][U];
	U^=(1<<x),res=0;
	for(;pos<n;pos++)if(in(U,pos))break;
	for(int u=U;u;u=(u-1)&U){
		if(!in(u,pos))continue;
		bool ok=true;
		for(int i=0;i<p;i++)if(l[i].second==x&&in(u,l[i].first.first)&&in(u,l[i].first.second)){ok=false;break;}
		if(!ok)continue;
		for(int i=0;i<p;i++)if(in(u,l[i].second)&&(!in(u,l[i].first.first)||!in(u,l[i].first.second))){ok=false;break;}
		if(!ok)continue;
		for(int i=0;i<m;i++)if(e[i].first!=x&&e[i].second!=x&&(in(u,e[i].first)^in(u,e[i].second))){ok=false;break;}
		if(!ok)continue;
		int cnt=0,y;
		for(int i=0;i<n;i++)if(g[x][i]&&in(u,i))cnt++,y=i;
		if(cnt>1)continue;
		if(cnt==1)res+=dfs(y,u)*dfs(x,U^u^(1<<x));
		else for(y=0;y<n;y++)if(in(u,y))res+=dfs(y,u)*dfs(x,U^u^(1<<x));
	}
//	printf("%d,%d:%d\n",x,U,res);
	return res;
}
signed main(){
	scanf("%lld%lld%lld",&n,&m,&p),memset(f,-1,sizeof(f));
	for(int i=0,x,y;i<m;i++)scanf("%lld%lld",&x,&y),x--,y--,g[x][y]=g[y][x]=true,e[i]=make_pair(x,y);
	for(int i=0,a,b,c;i<p;i++)scanf("%lld%lld%lld",&a,&b,&c),a--,b--,c--,l[i]=make_pair(make_pair(a,b),c);
	for(int i=0;i<n;i++)f[i][1<<i]=1;
	printf("%lld\n",dfs(0,(1<<n)-1));
	return 0;
}