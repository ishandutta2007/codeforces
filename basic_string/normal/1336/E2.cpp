#include<bits/stdc++.h>
using namespace std;
enum{P=998244353,N=57};
using ll=long long;
int c[N][N],t,ans[N];
ll v[N],a[N];
bool b[N];
int qp(int a,int b){int r=1;for(;b;b>>=1,a=a*1ll*a%P)if(b&1)r=r*1ll*a%P;return r;}
void dfs(int x,ll y){
	if(x>t){++ans[__builtin_popcountll(y)];return;}
	dfs(x+1,y),dfs(x+1,y^a[x]);
}
int main(){ios::sync_with_stdio(0);cin.tie(0);
	int n,m,i,j,k,l;
	ll x;
	cin>>n>>m;
	for(j=1;j<=n;++j){
		cin>>x;
		for(i=m-1;~i;--i)if(x>>i&1){
			if(!v[i]){v[i]=x;break;}
			x^=v[i];
		}
	}
	for(i=0;i<m;++i)if(v[i])a[++t]=v[i],b[i]=1;
	if(t<27){
		dfs(1,0);
		for(i=0;i<=m;++i)cout<<qp(2,n-t)*1ll*ans[i]%P<<' ';
		return 0;
	}
	for(c[0][0]=i=1;i<=m;++i)for(c[i][0]=j=1;j<=i;++j)c[i][j]=(c[i-1][j-1]+c[i-1][j])%P;
	for(i=m-1;~i;--i)for(j=i-1;~j;--j)if(v[i]>>j&1)v[i]^=v[j];
	for(i=0;i<m;++i)v[i]|=(1ll<<i);
	for(i=m-1;~i;--i)for(j=i-1;~j;--j)if(v[i]>>j&1)v[j]|=(1ll<<i);
	for(i=t=0;i<m;++i)if(!b[i])a[++t]=v[i];
	dfs(1,0);
	for(i=0;i<=m;++i){
		l=0;
		for(j=0;j<=m;++j)for(k=0;k<=i;++k)l=(l+ans[j]*((k&1)?-1ll:1ll)*c[m-j][i-k]%P*c[j][k])%P;
		cout<<(l*1ll*qp(2,n)%P*qp((P+1)/2,m)%P+P)%P<<' ';
	}
}