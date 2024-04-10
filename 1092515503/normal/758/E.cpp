#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll mnw[200100],f[200100],rec[200100];
struct EDGE{
	int x,y,str,wei;
}e[200100];
vector<int>v[200100];
void dfs1(int x,int fa){
	for(auto i:v[x]){
		int y=e[i].x^e[i].y^x;
		if(y==fa)continue;
		dfs1(y,x);
		if(mnw[y]>e[i].str){puts("-1");exit(0);}
		mnw[x]+=mnw[y]+e[i].wei-min(e[i].str-mnw[y],e[i].wei-1ll);
	}
}
void dfs2(int x,int fa){
	for(auto i:v[x]){
		int y=e[i].x^e[i].y^x;
		if(y==fa)continue;
		dfs2(y,x);
		if(f[y]>e[i].str)rec[y]=f[y]-e[i].str;
		f[x]+=f[y]-rec[y]+e[i].wei;
	}
}
int dfs3(int x,int fa){
	f[x]-=rec[x];
	for(auto i:v[x]){
		int y=e[i].x^e[i].y^x;
		if(y==fa)continue;
		ll ass=min(rec[x],f[y]-mnw[y]-rec[y]);
		rec[y]+=ass,rec[x]-=ass;
		rec[x]+=dfs3(y,x);
		ll delta=min({e[i].str-f[y],rec[x],e[i].wei-1ll});
		e[i].wei-=delta,e[i].str-=delta;
		rec[x]-=delta;
	}
	return rec[x];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++)scanf("%d%d%d%d",&e[i].x,&e[i].y,&e[i].wei,&e[i].str),v[e[i].x].push_back(i),v[e[i].y].push_back(i);
	dfs1(1,0),dfs2(1,0),dfs3(1,0);
	printf("%d\n",n);
	for(int i=1;i<n;i++)printf("%d %d %d %d\n",e[i].x,e[i].y,e[i].wei,e[i].str);
	return 0;
}