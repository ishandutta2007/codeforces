#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,cc,ans[N],s[N],f[N][5555];
inline void init()
{
	for(int i=1;i<N;i++)s[i]=i*(i+1)/2;
	f[0][0]=1;
	for(int i=1;i<N;i++)f[i][s[i]]=1;
	for(int i=4;i<N;i++)f[i][i+1]=1;
	for(int i=1;i<N;i++)for(int j=i;j<=s[i];j++)if(f[i][j])
	{
		for(int k=2;k<=N-i;k++)f[i+k-1][j+s[k]-1]=1;
		for(int k=4;k<=N-i;k++)f[i+k-1][j+k]=1;
	}
}
void dfs(int l,int r,int n,int k,int op)
{
	if(k==n*(n+1)/2)
	{
		if(op==0)for(int i=l;i<=r;i++)ans[i]=++cc;
		else for(int i=r;i>=l;i--)ans[i]=++cc;return;
	}
	for(int i=2;i<=n;i++)if(k-s[i]+1>0&&f[n-i+1][k-s[i]+1])
	{
		if(!op)
		{
			dfs(l,r-i+1,n-i+1,k-s[i]+1,1);
			for(int j=r-i+2;j<=r;j++)ans[j]=++cc;
		}
		else
		{
			dfs(l+i-1,r,n-i+1,k-s[i]+1,0);
			for(int j=l+i-2;j>=l;j--)ans[j]=++cc;
		}
		return;
	}
	for(int i=4;i<=n;i++)if(k-i>0&&f[n-i+1][k-i])
	{
		for(int j=r-i+2;j<=r;j+=2)ans[j]=++cc;
		dfs(l,r-i+1,n-i+1,k-i,0);
		for(int j=r-i+3;j<=r;j+=2)ans[j]=++cc;
		if(i&1)swap(ans[r-2],ans[r]);
		return;
	}
}
void sol()
{
	int n,k;cc=0;scanf("%d%d",&n,&k);
	if(!f[n][k]){puts("NO");return;}
	dfs(1,n,n,k,0);puts("YES");
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);puts("");
}
int main(){init();int T;scanf("%d",&T);while(T--)sol();return 0;}