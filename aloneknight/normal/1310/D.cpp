#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
const int N=105;
int n,k,c[N],d[N][N],f[15][N];
int main()
{
	scanf("%d%d",&n,&k);
	rep(i,1,n)rep(j,1,n)scanf("%d",&d[i][j]);
	srand(time(0));int T=5000,ans=1e9;
	while(T--)
	{
		rep(i,1,n)c[i]=rand()&1;
		rep(i,0,k)rep(j,1,n)f[i][j]=1e9;
		f[0][1]=0;
		rep(t,0,k-1)rep(i,1,n)rep(j,1,n)if(c[i]^c[j])f[t+1][j]=min(f[t+1][j],f[t][i]+d[i][j]);
		ans=min(ans,f[k][1]);
	}
	printf("%d\n",ans);return 0;
}