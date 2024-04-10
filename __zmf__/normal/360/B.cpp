//zhouakngyang txdy!
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#define Macesuted cout<<"kawaii"<<endl
#define MatrixCascade cout<<"npsl"<<endl
#define Karry5307 cout<<"nmsl"<<endl
using namespace std;
#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
const int N=2009;
int n,k,l,r,ans;
int dp[N],a[N];
inline bool check(int x)
{
	for(int i=1;i<=n;i++)dp[i]=1;
	for(int i=2;i<=n;i++)
		for(int j=1;j<i;j++)	
			if(abs(a[i]-a[j])<=x*(i-j))dp[i]=max(dp[i],dp[j]+1);
	for(int i=1;i<=n;i++)
		if((i-dp[i])+(n-i)<=k)return 1;
	return 0;
}
signed main()
{
	n=read(),k=read();
	for(int i=1;i<=n;i++)a[i]=read();
	l=0,r=2e9,ans=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans<<endl;
	return 0;
}