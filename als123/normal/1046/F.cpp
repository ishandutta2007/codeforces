#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int Maxn=200010;
LL read()
{
	LL x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
LL a[Maxn];
int main()
{
	LL n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	LL x=read(),f=read(),ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<=x)continue;
		if(a[i]-f<=x){ans++;continue;}
		ans+=((a[i]-x)/(x+f));
		if((a[i]-x)%(x+f))ans++;
	}
	ans*=f;
	printf("%lld",ans);
}