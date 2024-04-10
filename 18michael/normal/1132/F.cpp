#include<cstdio>
int n,Test_num;
char c;
char ch[502];
int f[502][502];
inline int min(int a,int b)
{
	return a<b? a:b;
}
int main()
{
	scanf("%d%s",&n,ch+1);
	for(int i=1,n1;i<=n;++i)
	{
		n1=n-i+1;
		for(int j=1;j<=n1;++j)
			f[j][i]=i;
	}
	for(int i=2,n1;i<=n;++i)
	{
		n1=n-i+1;
		for(int j=1;j<=n1;++j)
		{
			c=ch[j+i-1];
			for(int k=1;k<i;++k)
				f[j][i]=min(f[j][i],f[j][k]+f[j+k][i-k]-(ch[j+k-1]==c));
		}
	}
	printf("%d",f[1][n]);
	return 0;
}