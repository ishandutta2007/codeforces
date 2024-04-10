#include<cstdio>
#include<algorithm>
using namespace std;
#define N 405
int T,n,m,su[N][N],v1[N],v2[N],s1[N];
char s[N][N];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)su[i][j]=su[i][j-1]+(s[i][j]=='1');
		int as=1e9;
		for(int i=1;i<=m;i++)
		for(int j=i+3;j<=m;j++)
		{
			for(int l=1;l<=n;l++)
			{
				v1[l]=(su[l][j-1]-su[l][i])+(s[l][i]=='0')+(s[l][j]=='0');
				v2[l]=(j-i-1)-(su[l][j-1]-su[l][i]);
				s1[l]=s1[l-1]+v1[l];
			}
			int mn=1e9;
			for(int l=5;l<=n;l++)
			{
				mn=min(mn+v1[l-1],v2[l-4]+s1[l-1]-s1[l-4]);
				as=min(as,mn+v2[l]);
			}
		}
		printf("%d\n",as);
	}
}