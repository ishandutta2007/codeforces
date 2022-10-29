#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=300005;
int q,n,i,j,k,a[N],b[N];
ll w,f[N][3];
int Abs(int a)
{
	return a>0?a:-a;
}
int main()
{
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;++i)
			scanf("%d%d",a+i,b+i);
		f[0][0]=0;f[0][1]=f[0][2]=1ll<<60;
		for(i=1;i<=n;++i)
		{
			for(j=0;j<=2;++j)
			{
				f[i][j]=1ll<<60;
				for(k=0;k<=2;++k)
					if(a[i]+j!=a[i-1]+k)
						f[i][j]=min(f[i][j],f[i-1][k]+j*b[i]);
			}
		}
		printf("%lld\n",min(f[n][0],min(f[n][1],f[n][2])));
	}
	return 0;
}