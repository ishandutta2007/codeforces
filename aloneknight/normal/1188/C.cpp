#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1005,P=998244353;
int n,k,m,ans,a[N],f[N][N];
int main()
{
	scanf("%d%d",&n,&k);m=100000;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int w=1;w<=m/(k-1)+1;++w)
	{
		f[0][0]=1;
		for(int i=1,r=0;i<=n;++i)
		{
			while(a[r+1]+w<=a[i])r++;f[i][0]=f[i-1][0];
			for(int j=1;j<=i&&j<=k;++j)f[i][j]=(f[i-1][j]+f[r][j-1])%P;
		}
		ans=(ans+f[n][k])%P;
	}
	printf("%d\n",ans);
	return 0;
}