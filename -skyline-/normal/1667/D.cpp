#include<bits/stdc++.h>
#define ll   long long
#define pb   push_back
#define mp   make_pair
#define orz  1000000007
using namespace std;
int T,n,d[200005],a[200005],f[200005];
vector<int> v[200005];
bool ok;
void dfs(int x,int y){
	f[x]=y;
	int cnt[2]={};
	for(int i=0;i<v[x].size();++i)if(v[x][i]!=y)dfs(v[x][i],x),++cnt[a[v[x][i]]];
	if(y){
		if(cnt[1]>cnt[0])a[x]=0;
		else a[x]=1;
		++cnt[a[x]];
	}
	if(cnt[0]!=(d[x]>>1))ok=0;
}
void prt(int x,int y){
	vector<int> V[2];
	for(int i=0;i<v[x].size();++i)if(v[x][i]!=y)V[a[v[x][i]]].pb(v[x][i]);
	if(y)V[a[x]].pb(x);
	for(int i=d[x];i;--i){
		int k=V[i&1][V[i&1].size()-1];
		if(k==x)printf("%d %d\n",x,y);
		else prt(k,x);
		V[i&1].pop_back();
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)v[i].clear(),d[i]=0;
		for(int i=1;i<n;++i){
			int x,y;
			scanf("%d%d",&x,&y);
			v[x].pb(y),v[y].pb(x);
			++d[x],++d[y];
		}
		ok=1;
		dfs(1,0);
		if(!ok){
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		prt(1,0);
	}
    return 0;
}