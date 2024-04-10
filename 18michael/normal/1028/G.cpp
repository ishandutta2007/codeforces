#include<bits/stdc++.h>
#define Mx 10000
#define LL long long
using namespace std;
LL l=1,r=10004205361450474,t;
LL f[6][10002];
int main()
{
	for(int i=1;i<=Mx;++i)f[1][i]=i;
	for(int i=2;i<=5;++i)
		for(int j=1;j<=Mx;++j)
		{
			for(int k=0;k<=j;++k)
			{
				if(j+f[i][j]>=Mx)
				{
					f[i][j]+=(f[i-1][Mx]+1)*(j-k+1);
					break;
				}
				f[i][j]+=f[i-1][j+f[i][j]]+1;
			}
			--f[i][j];
		}
	for(int i=5,x;i;--i)
	{
		t=0,printf("%lld ",min(l,(LL)Mx));
		for(int j=min(l,(LL)Mx);j;--j)printf("%lld ",l+(t+=f[i-1][min(l+t,(LL)Mx)]+1)-1);
		puts(""),fflush(stdout),scanf("%d",&x);
		if(x<0)return 0;
		t=0;
		for(int j=1;j<=x;++j)t+=f[i-1][min(l+t,(LL)Mx)]+1;
		l+=t;
	}
	return 0;
}