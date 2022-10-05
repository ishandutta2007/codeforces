#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
basic_string<int>g[N],a[N],b[N];
basic_string<long long>s[N];
map<pair<int,int>,double>mp;
int r,sz[N],f[N],d[N][2],e[N],h[N];
void dfs(int x,int y){
	for(int i:g[x])if(i!=y){
		dfs(i,x);
		if(d[i][0]+1>d[x][0])d[x][1]=d[x][0],d[x][0]=d[i][0]+1;
		else if(d[i][0]+1>d[x][1])d[x][1]=d[i][0]+1;
	}
	f[x]=r,++sz[r],h[r]=max(h[r],d[x][0]+d[x][1]);
}
void dfs2(int x,int y){
	if(y){
		e[x]=e[y]+1;
		if(d[y][0]==d[x][0]+1)e[x]=max(e[x],d[y][1]+1);
		else e[x]=max(e[x],d[y][0]+1);
	}
	++a[r][max(d[x][0],e[x])];
	for(int i:g[x])if(i!=y)dfs2(i,x);
}
int main(){
	int n,m,q,i,j,k,l;
	long long w;
	scanf("%d%d%d",&n,&m,&q);
	while(m--)scanf("%d%d",&i,&j),g[i]+=j,g[j]+=i;
	for(i=1;i<=n;++i)if(!f[i]){
		dfs(r=i,0),a[i].resize(h[i]+1),dfs2(i,0),b[i].resize(h[i]+1),s[i].resize(h[i]+1);
		s[i][h[i]]=h[i]*1ll*a[i][h[i]],b[i][0]=a[i][0];
		for(j=1;j<=h[i];++j)b[i][j]=a[i][j]+b[i][j-1];
		for(j=h[i]-1;~j;--j)s[i][j]=j*1ll*a[i][j]+s[i][j+1];
	}
	while(q--){
		if(scanf("%d%d",&i,&j),i=f[i],j=f[j],h[i]>h[j])swap(i,j);
		if(i==j)puts("-1");else if(mp[{i,j}])printf("%.9lf\n",mp[{i,j}]);else{
			for(k=w=0;k<=h[i];++k){
				if(h[j]-k>=1)l=b[j][h[j]-k-1],w+=a[i][k]*1ll*(s[j][h[j]-k]+l*1ll*h[j]+(sz[j]-l)*1ll*(k+1));
				else w+=a[i][k]*1ll*(s[j][0]+sz[j]*1ll*(k+1));
			}
			printf("%.9lf\n",mp[{i,j}]=w*1.0/sz[i]/sz[j]);
		}
	}
	return 0;
}