#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int pos[200005];
int a[200005];
int ans[200005];
bool bi(int c,int d)
{
	return a[c]>a[d];
}
signed main()
{
	int t,n,sl=0;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read(),pos[i]=i;
		sort(pos+1,pos+n+1,bi);
		sl=0;
		for(int i=1;i<=n;i++)
		{
			if(i%2==0)ans[pos[i]]=-i/2;
			else ans[pos[i]]=(i+1)/2;
			sl+=(i+1)/2*a[pos[i]];
		}
		printf("%lld\n",sl*2);
		ans[0]=0;
		for(int i=0;i<=n;i++)printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}