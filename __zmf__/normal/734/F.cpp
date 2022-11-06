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
const int N=2e5+9;
int n,b[N],c[N],p[N],sum,pp,a[N],cnt[32];
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)b[i]=read();
	for(int i=1;i<=n;i++)c[i]=read();
	for(int i=1;i<=n;i++)p[i]=b[i]+c[i],sum+=p[i];
	if(sum%(n*2)!=0)
	{
		puts("-1");return 0;
	}
	pp=sum/(n*2);
	for(int i=1;i<=n;i++)
	{
		if((p[i]-pp)<0)
		{
			puts("-1");return 0;
		}
		if((p[i]-pp)%n!=0)
		{
			puts("-1");return 0;
		}
		a[i]=(p[i]-pp)/n;
		for(int j=0;j<32;j++)
			if((a[i]&(1<<j)))cnt[j]++;
	}
	for(int i=1;i<=n;i++)
	{
		int res=0;
		for(int j=0;j<32;j++)
			if((a[i]&(1<<j)))res=res+cnt[j]*(1<<j);
		if(res!=b[i])
		{
			puts("-1");return 0;
		}
	}
	for(int i=1;i<=n;i++)printf("%lld ",a[i]);
	//cout<<ans<<endl;
	return 0;
}