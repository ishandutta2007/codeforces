#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
long long taxi,n,q,a[100009],x,sum[100009],cnt;
bool k[20000009];
map<long long,int>G;
inline void work(int l,int r,bool val)
{
	if(G[sum[r]-sum[l-1]]==0)G[sum[r]-sum[l-1]]=++cnt;
	k[G[sum[r]-sum[l-1]]]=val;
	int mid_val=(a[l]+a[r])/2;
	if(a[r]==a[l])
	{
		return ;
	}
	int mid=upper_bound(a+l+1,a+r+1,mid_val)-a;
	work(l,mid-1,val);work(mid,r,val);
	return ;
}
int main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		n=read(),q=read();
		for(int i=1;i<=n;i++)a[i]=read();
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
		work(1,n,1);
		for(int i=1;i<=q;i++)
		{
			x=read();
			if(G[x]&&k[G[x]]==1)puts("Yes");
			else puts("No");
		}
		work(1,n,0);
	}
	return 0;
}