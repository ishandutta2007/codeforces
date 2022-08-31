#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 333;
const int MO = 998244353;
void ad(int&x,int y){
	x+=y;
	if(x>=MO)
		x-=MO;
}
int mul(int x,int y){
	return (LL)x*y%MO;
}
int n,k,d[N],c[N],f[N][N],g[N][N],ans[N];
vector<int> v[N];
int F[N],G[N];
void mrg(int x,int y,int fl){
	int i,j;
	for(i=d[x];i<=c[x];i++){
		for(j=d[y];j<=c[y];j++){
			ad(F[max(i,j)],mul(f[x][i],f[y][j]));
			ad(G[min(i,j)],mul(g[x][i],g[y][j]));
			if(i+j-d[x]*2<=k){
				ad(G[j],mul(f[x][i],g[y][j]));
				ad(G[i],mul(g[x][i],f[y][j]));
			}
			else{
				ad(F[i],mul(f[x][i],g[y][j]));
				ad(F[j],mul(g[x][i],f[y][j]));
			}
		}
	}
	c[x]=max(c[x],c[y]);
	for(i=d[x];i<=c[x];i++)
		f[x][i]=F[i],g[x][i]=G[i],F[i]=0,G[i]=0;
}
void solve(int u,int fa){
	int i,x,fl=1;
	d[u]=d[fa]+1;
	c[u]=d[u];
	g[u][d[u]]=1;
	f[u][d[u]]=1;
	for(i=0;i<v[u].size();i++){
		x=v[u][i];
		if(x==fa)
			continue;
		solve(x,u);
		mrg(u,x,fl);
	}
}
int main(){
	int i,x,y,s,w;
	cin>>n;
	for(i=1;i<n;i++){
		cin>>x>>y;
		//x=i+1,y=x-1;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(k=1;k<=n;k++){
		solve(1,0);
		for(i=1;i<=n;i++)
			ad(ans[k],g[1][i]);
		//cout<<k<<' '<<ans[k]<<endl;
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
	}
	w=1;
	for(i=1;i<=n;i++)
		w=mul(w,2);
	s=MO-1;
	for(i=1;i<=n;i++){
		ad(s,w);
		ad(s,MO-ans[i]);
	}
	w=1;
	for(i=1;i<=n;i++)
		w=mul(w,(MO+1)/2);
	printf("%d\n",mul(s,w));
	return 0;
}