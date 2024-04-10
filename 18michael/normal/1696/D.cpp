#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define Mx 19
#define eps 1e-9
#define LL long long
#define inf 0x3f3f3f3f
using namespace std;
int n,Test_num;
int a[1000002],dp[1000002];
typedef pair<int,int> P;
P mn[1000002][22],mx[1000002][22];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline P mergemn(P a,P b)
{
	return a.first<b.first? a:b;
}
inline P mergemx(P a,P b)
{
	return a.first>b.first? a:b;
}
inline P getmn(int x,int y)
{
	int len=log2(y-x+1)+eps;
	return mergemn(mn[x][len],mn[y-(1<<len)+1][len]);
}
inline P getmx(int x,int y)
{
	int len=log2(y-x+1)+eps;
	return mergemx(mx[x][len],mx[y-(1<<len)+1][len]);
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n);
		for(int i=1;i<=n;++i)read(a[i]),dp[i]=inf,mn[i][0]=mx[i][0]=P(a[i],i);
		for(int i=1;i<=Mx;++i)for(int j=1;j+(1<<i)-1<=n;++j)mn[j][i]=mergemn(mn[j][i-1],mn[j+(1<<(i-1))][i-1]),mx[j][i]=mergemx(mx[j][i-1],mx[j+(1<<(i-1))][i-1]);
		dp[1]=0;
		for(int i=1,l,r,mid;i<=n;++i)
		{
			for(l=i,r=n;l<=r;)
			{
				mid=((l+r)>>1);
				if(getmn(i,mid).first==a[i])l=mid+1;
				else r=mid-1;
			}
			r=getmx(i,r).second,dp[r]=min(dp[r],dp[i]+1);
			for(l=i,r=n;l<=r;)
			{
				mid=((l+r)>>1);
				if(getmx(i,mid).first==a[i])l=mid+1;
				else r=mid-1;
			}
			r=getmn(i,r).second,dp[r]=min(dp[r],dp[i]+1);
		}
		printf("%d\n",dp[n]);
	}
	return 0;
}