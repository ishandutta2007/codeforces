#include<bits\stdc++.h>
using namespace std;
int n,t,head,tail,mn,mx,mn1,mx1;
int a[5002],l[5002],r[5002],dp[5002],q[5002],ans[5002];
bool cnt[5002]={};
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1;i<=n;++i)if(!l[a[i]])l[a[i]]=i;
	for(int i=n;i;--i)if(!r[a[i]])r[a[i]]=i;
	for(int i=1;i<=n;++i)
	{
		if(l[a[i]]==r[a[i]]){ans[i]=dp[i]=ans[i-1]+a[i];continue;}
		t=0,q[head=tail=1]=i,mn=mx=i;
		while(head<=tail)
		{
			mn1=min(mn,l[a[q[head]]]),mx1=max(mx,r[a[q[head]]]),++head;
			for(int j=mn1;j<mn;++j)q[++tail]=j;
			for(int j=mx+1;j<=mx1;++j)q[++tail]=j;
			mn=mn1,mx=mx1;
		}
		if(mx>i){ans[i]=ans[i-1];continue;}
		for(int j=mn;j<=i;++j)if(!cnt[a[j]])cnt[a[j]]=1,t^=a[j];
		dp[i]=ans[mn-1]+t;
		for(int j=mn;j<=i;++j)cnt[a[j]]=0;
		ans[i]=max(ans[i-1],dp[i]);
	}
	printf("%d",ans[n]);
	return 0;
}