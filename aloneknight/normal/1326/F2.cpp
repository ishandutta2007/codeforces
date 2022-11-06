#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define db double
#define ld long double
#define pii pair<int,int> 
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define vii vector<vi>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
#define fore(i,a) for(int i=0;i<a.size();++i) 
const int N=19,M=1<<18;
int n,m,nn,a[N][N],p2[N],d[N],p[N],vis[N],sz[M];ll val,f[N][M],b[N][M],c[N][M],ans[M];char s[N][N];
inline void fwt(int n,ll*a,int f){for(int i=1;i<n;i*=2)for(int j=0;j<n;j+=2*i)for(int k=0;k<i;k++)a[i+j+k]+=a[j+k]*f;}
inline ll calc(ll *a){ll s=0;rep(i,0,nn)s+=a[i]*((n-sz[i])&1?-1:1);return s;}
void dfs2(int x)
{
	if(x>m)
	{
		int s=0;
		for(int i=1,t=0;i<=m;i++,t++)rep(j,1,p[i])s+=p2[t++];
		ans[s]+=val;return;
	}
	for(int i=1;i<=m;i++)if(!vis[i])
	{
		if(d[i]==d[i-1]&&!vis[i-1])continue;
		vis[i]=1;p[x]=d[i];dfs2(x+1);vis[i]=0;
	}
}
void dfs1(int x,int lst,int sum)
{
	if(sum>n)return;
	if(sum==n){val=calc(c[x]);m=x;dfs2(1);return;}
	for(int i=lst;i<=n-sum;i++)
	{
		rep(j,0,nn)c[x+1][j]=c[x][j]*b[i][j];
		d[x+1]=i;dfs1(x+1,i,sum+i);
	}
}
int main()
{
	p2[0]=1;rep(i,1,19)p2[i]=2*p2[i-1];
	scanf("%d",&n);nn=1<<n;
	rep(i,0,n)scanf("%s",s[i]);
	rep(i,0,n)rep(j,0,n)a[i][j]=s[i][j]-'0';
	rep(i,1,nn)sz[i]=sz[i>>1]+(i&1);
	rep(i,0,n)f[i][p2[i]]=1;
	rep(s,1,nn)rep(i,0,n)if(f[i][s])rep(j,0,n)if((~s>>j&1)&&a[i][j])f[j][s^p2[j]]+=f[i][s];
	rep(s,1,nn)rep(i,0,n)b[sz[s]][s]+=f[i][s];
	rep(i,1,n+1)fwt(nn,b[i],1);
	c[0][0]=1;fwt(nn,c[0],1);dfs1(0,1,0);
	rep(i,0,n-1)rep(s,0,nn)if(~s>>i&1)ans[s]-=ans[s^p2[i]];
	rep(i,0,p2[n-1])printf("%lld ",ans[i]);return 0;
}