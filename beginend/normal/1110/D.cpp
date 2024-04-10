#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=1000005;
const int inf=1e9;

int n,m,s[N],f[N][7][7];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		int x;scanf("%d",&x);
		s[x]++;
	}
	for (int j=0;j<=std::min(s[1],6);j++)
		for (int k=0;k<=std::min(s[2],6);k++)
			f[2][j][k]=(s[1]-j)/3+(s[2]-k)/3;
	int ans=0;
	for (int i=2;i<m;i++)
		for (int j=std::min(3,s[i-1]);j>=0;j--)
			for (int k=std::min(6,s[i]);k>=j;k--)
				for (int l=std::min(6,s[i+1]-j);l>=k-j;l--)
					f[i+1][k-j][l]=std::max(f[i+1][k-j][l],f[i][j][k]+j+(s[i+1]-j-l)/3);
	for (int i=2;i<=m;i++)
		for (int j=0;j<=6;j++)
			for (int k=0;k<=6;k++)
				ans=std::max(ans,f[i][j][k]);
	printf("%d\n",ans);
	return 0;
}