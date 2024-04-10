#include<iostream>
#include<cstdio>
using namespace std;
int n,ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		for(int j=i,k;j<=n;++j)
		{
			k=i^j;
			if(k>=j&&1<=k&&k<=n&&i+j>k&&i+k>j&&j+k>i)++ans;
		}
	}
	printf("%d",ans);
	return 0;
}