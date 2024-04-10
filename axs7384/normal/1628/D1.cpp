#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;
const int inv2=5e8+4;
int f[2005][2005];
int n,m,k,t;
inline void prework()
{
	int n=2000;
	for (int i=0;i<=n;++i)
	{
		f[i][i]=i;
		f[i][0]=0;
	}
	for (int i=1;i<=n;++i)
		for (int j=1;j<i;++j)
			f[i][j]=(ll)(f[i-1][j-1]+f[i-1][j])*inv2%mod;
	// cout<<"??"<<f[2][1]<<endl;
}
int main()
{
	prework();
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		printf("%lld\n",(ll)f[n][m]*k%mod);
	}
	return 0;
}