#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,m,Mx,Testnum;
int b[14],lg[4102];
LL res[4102];
int a[14][2002];
LL dp[2002][4102],mx[2002][4102];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline int lowbit(int x)
{
	return x&(-x);
}
int main()
{
	for(int i=0;i<=12;++i)lg[(1<<i)]=i;
	read(Testnum),res[0]=0;
	while(Testnum--)
	{
		read(n),read(m),Mx=(1<<n);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				read(a[i][j]);
		for(int i=1;i<=m;++i)
		{
			for(int j=0;j<Mx;++j)mx[i][j]=0;
			for(int j=1;j<=n;++j)
			{
				for(int k=1;k<=n;++k)b[k]=a[(k+j-1)%n+1][i];
				for(int k=1,l;k<Mx;++k)res[k]=0,l=lowbit(k),res[k]=res[k^l]+b[lg[l]+1];
				for(int k=0;k<Mx;++k)mx[i][k]=max(mx[i][k],res[k]);
			}
		}
		for(int i=1;i<=m;++i)
			for(int j=0;j<Mx;++j)
			{
				dp[i][j]=0;
				for(int k=j;;k=(k-1)&j)
				{
					dp[i][j]=max(dp[i][j],dp[i-1][k]+mx[i][j^k]);
					if(!k)break;
				}
			}
		printf("%lld\n",dp[m][Mx-1]);
	}
	return 0;
}