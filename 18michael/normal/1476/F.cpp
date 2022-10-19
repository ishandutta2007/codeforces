#include<bits/stdc++.h>
#define Mx 18
#define eps 1e-9
using namespace std;
int n,Test_num;
int p[300002];
typedef pair<int,int> P;
P dp[300002];
int mx[300002][22];
inline P merge(P a,P b)
{
	return a.first>b.first? a:b;
}
inline int getmx(int x,int y)
{
	int len=log2(y-x+1)+eps;
	return max(mx[x][len],mx[y-(1<<len)+1][len]);
}
inline int find(int x,int r)
{
	int l=0,mid;
	for(;l<=r;)
	{
		mid=((l+r)>>1);
		if(dp[mid].first<x)l=mid+1;
		else r=mid-1;
	}
	return l;
}
inline void print(int x)
{
	if(!x)return ;
	print(dp[x].second<=n? dp[x].second:dp[x].second-n);
	if(dp[x].second<=n)
	{
		for(int i=dp[x].second+1;i<x;++i)putchar('R');
		putchar('L');
	}
	else putchar('R');
}
inline void solve()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&p[i]),mx[i][0]=i+p[i];
	for(int i=1;i<=Mx;++i)for(int j=1;j+(1<<i)-1<=n;++j)mx[j][i]=max(mx[j][i-1],mx[j+(1<<(i-1))][i-1]);
	for(int i=1,j;i<=n;++i)
	{
		dp[i]=P(dp[i-1].first,i-1);
		if(dp[i-1].first>=i)dp[i]=merge(dp[i],P(i+p[i],i-1+n));
		if((j=find(i-p[i]-1,i-1))<i)
		{
			dp[i]=merge(dp[i],P(i-1,j));
			if(j+1<i)dp[i]=merge(dp[i],P(getmx(j+1,i-1),j));
		}
	}
	if(dp[n].first<n)return (void)(puts("NO"));
	puts("YES"),print(n),puts("");
}
int main()
{
	for(scanf("%d",&Test_num);Test_num--;)solve();
	return 0;
}