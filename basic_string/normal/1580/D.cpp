#include<bits/stdc++.h>
using namespace std;
enum{N=4009};
int n,m,a[N],sz[N],lc[N],rc[N];
long long f[N][N];
int bd(int l,int r){
	if(l==r)return l;
	if(l>r)return 0;
	int i,j=l;
	for(i=l+1;i<=r;++i)if(a[i]<a[j])j=i;
	lc[j]=bd(l,j-1);
	rc[j]=bd(j+1,r);
	return j;
}
void dfs(int x){
	if(!x)return;
	int i,j,k,l;
	long long w;
	sz[x]=1,dfs(lc[x]),dfs(rc[x]),k=lc[x],l=rc[x],sz[x]+=sz[k]+sz[l];
	for(i=min(sz[k],m);~i;--i)for(j=min(sz[l],m-i);~j;--j){
		w=f[k][i]+f[l][j];
		f[x][i+j]=max(f[x][i+j],-a[x]*1ll*i*j*2+w);
		f[x][i+j+1]=max(f[x][i+j+1],a[x]*1ll*(m-(i+1)*(j+1)*2+1)+w);
	}
}
int main(){ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	int i,j,k,rt;
	for(i=1;i<=n;++i)cin>>a[i];
	rt=bd(1,n);
	dfs(rt);
	cout<<f[rt][m];
	return 0;
}