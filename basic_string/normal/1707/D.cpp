#include<bits/stdc++.h>
using namespace std;
enum{N=2009};
basic_string<int>e[N];
int n,p,c[N][N],f[N][N],pr[N][N],sf[N][N],sum[N],ans[N];
void dfs(int x,int y){
	e[x].erase(find(begin(e[x]),end(e[x]),y));
	int l=e[x].size(),i,j,v,w=0;
	for(int o:e[x])dfs(o,x);
	for(i=1;i<n;++i)pr[0][i]=sf[l][i]=1;
	for(i=0;i<l;++i){
		v=e[x][i];
		for(j=1;j<n;++j)pr[i+1][j]=pr[i][j]*1ll*f[v][j]%p;
	}
	for(i=l-1;~i;--i){
		v=e[x][i],sum[i]=0;
		for(j=1;j<n;++j)sf[i][j]=sf[i+1][j]*1ll*f[v][j]%p;
	}
	for(i=1;i<n;++i){
		w=(w+sf[0][i])%p,f[x][i]=w*(1ll-l)%p;
		for(j=0;j<l;++j){
			sum[j]=(sum[j]+pr[j][i]*1ll*sf[j+1][i])%p;
			f[x][i]=(f[x][i]+f[e[x][j]][i]*1ll*sum[j])%p;
		}
	}
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int i,j,k;
	cin>>n>>p;
	for(i=0;i<n;++i)for(c[i][0]=j=1;j<=i;++j)
	c[i][j]=(c[i-1][j-1]+c[i-1][j])%p;
	for(i=1;i<n;++i){
		cin>>j>>k,ans[i]=1;
		e[j]+=k,e[k]+=j; 
	}
	for(int o:e[1]){
		dfs(o,1);
		for(i=1;i<n;++i)ans[i]=ans[i]*1ll*f[o][i]%p;
	}
	for(i=1;i<n;++i)for(j=1;j<i;++j)
	ans[i]=(ans[i]-ans[j]*1ll*c[i][j])%p;
	for(i=1;i<n;++i)cout<<(ans[i]+p)%p<<' ';
}