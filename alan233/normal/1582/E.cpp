// sb
#include <bits/stdc++.h>
using namespace std;

int T,n,ans;
long long a[100010],s[100010],f[100010][500];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			s[i]=s[i-1]+a[i];
		}
		f[n+1][0]=2e9;
		for(int i=1;i<=498;i++) f[n+1][i]=0;
		for(int i=n;i;i--)
			for(int j=0;j<=498;j++)
			{
				f[i][j]=f[i+1][j];
				if(j!=0&&i+j-1<=n&&f[i+j][j-1]>s[i+j-1]-s[i-1])
					f[i][j]=max(f[i][j],s[i+j-1]-s[i-1]);
			}
		ans=0;
		for(int i=0;i<=498;i++)
			if(f[1][i]) ans=i;
		printf("%d\n",ans);
	}
	return 0;
}