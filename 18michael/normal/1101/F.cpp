#include<bits/stdc++.h>
#define LL long long
#define inf 1000000000000000000
using namespace std;
int n,m;LL L,R,mid,ans=0;
LL a[402];int s[250002],f[250002],c[250002],r[250002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool check(LL x,int y)
{
	int now=s[y],L,R,mid;
	for(int i=0;i<=r[y];++i)
	{
		L=now+1,R=n;
		while(L<=R)
		{
			mid=((L+R)>>1);
			if(a[now]+x/c[y]>=a[mid])L=mid+1;
			else R=mid-1;
		}
		if((now=R)>=f[y])return 1;
	}
	return 0;
}
int main()
{
	srand(time(NULL)),read(n),read(m);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1;i<=m;++i)read(s[i]),read(f[i]),read(c[i]),read(r[i]);
	for(int i=1,j;i<=m;++i)j=rand()%m+1,swap(s[i],s[j]),swap(f[i],f[j]),swap(c[i],c[j]),swap(r[i],r[j]);
	for(int i=1;i<=m;++i)
	{
		if(check(ans,i))continue;
		L=ans+1,R=inf;
		while(L<=R)
		{
			mid=((L+R)>>1);
			if(check(mid,i))R=mid-1;
			else L=mid+1;
		}
		ans=max(ans,L);
	}
	return 0&printf("%lld",ans);
}