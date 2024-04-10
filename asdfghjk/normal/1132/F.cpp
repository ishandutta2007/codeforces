#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,i,j,k,l,x,y,f[505][505];
char s[505];
int main()
{
	scanf("%d%s",&n,s+1);
	for(i=1;i<=n;++i)
		f[i][i]=1;
	for(l=2;l<=n;++l)
		for(i=1,j=l;j<=n;++i,++j)
		{
			f[i][j]=1<<30;
			for(k=i;k<j;++k)
				f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
			if(s[i]==s[j])
			{
				f[i][j]=min(f[i][j],f[i+1][j-1]+1);
				for(k=i+1;k<j;++k)
					if(s[k]==s[i])
						f[i][j]=min(f[i][j],f[i][k]+f[k][j]-1);
			}
		}
	printf("%d",f[1][n]);
	return 0;
}