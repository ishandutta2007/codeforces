#include<bits/stdc++.h>
#define N 13
#define F first
#define S second
using namespace std;
long long dp[N][1<<N];
int n;
int lca[N][N];
int con[N][N];
int ds_find(int *a,int x){
	if(a[x]==x) return x;
	return a[x]=ds_find(a,a[x]);
}
long long f(int u,int stat){
	if(dp[u][stat]>=0) return dp[u][stat];
	if(stat==0) return dp[u][stat]=1;
	int ch=0,a[N],b[N];
	for(int i=0;i<n;i++) a[i]=i,b[i]=1<<i;
	int v=__lg(stat&-stat);
	for(int i=0;i<n;i++){
		if(!(stat&(1<<i))) continue;
		if(con[u][i]) ch|=(1<<i);
		if(lca[u][i]!=-1&&lca[u][i]!=u) return dp[u][stat]=0;
		for(int j=0;j<n;j++){
			if(!(stat&(1<<j))||j==i) continue;
			if(con[i][j]&&ds_find(a,i)!=ds_find(a,j)) b[a[j]]|=b[a[i]],a[a[i]]=a[j];
			if(lca[i][j]!=-1&&lca[i][j]!=u){
				if(!(1<<lca[i][j]&stat)) return dp[u][stat]=0;
				if(ds_find(a,i)!=ds_find(a,j)) b[a[j]]|=b[a[i]],a[a[i]]=a[j];
			}
		}
	}
	vector<int> block;
	block.push_back(ds_find(a,v));
	for(int i=0;i<n;i++){
		if((1<<i&stat)&&i==a[i]&&i!=a[v]){
			block.push_back(i);
		}
	}
	dp[u][stat]=0;
	for(int i=1;i<(1<<block.size());i+=2){
		int nxt=0;
		for(int j=0;j<block.size();j++){
			if(i&(1<<j)) nxt|=b[block[j]];
		}
		int tmp=nxt&ch;
		if((tmp&-tmp)!=tmp) continue;
		if(tmp){
			dp[u][stat]+=f(__lg(tmp),nxt^tmp)*f(u,stat^nxt);
		}
		else{
			for(int j=0;j<n;j++){
				if(!((1<<j)&nxt)) continue;
				dp[u][stat]+=f(j,nxt^(1<<j))*f(u,stat^nxt);
			}
		}
	}
	return dp[u][stat];
}
int main(){
	memset(dp,-1,sizeof(dp));
	memset(lca,-1,sizeof(lca));
	int m,q;
	bool wrong=false;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		x--,y--;
		con[x][y]=con[y][x]=1;
	}
	for(int i=0;i<q;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		x--,y--,z--;
		if(x==y){
			if(x!=z) wrong=true;
		}
		else if(lca[x][y]!=-1&&lca[x][y]!=z) wrong=true; 
		else lca[x][y]=lca[y][x]=z;
	}
	if(wrong) puts("0");
	else printf("%I64d\n",f(0,(1<<n)-2));
	return 0;
}