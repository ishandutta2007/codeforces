#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,n1,head=1,tail=1;
LL c;
int st[200002];
LL s[400002],f[200002];
inline LL to(int x,int y)
{
	return f[x]+min(s[(y<<1)-1]-s[x<<1],c);
}
inline int calc(int x,int y)
{
	int l=y+1,r=n,mid;
	for(;l<=r;)
	{
		mid=((l+r)>>1);
		if(to(x,mid)<=to(y,mid))r=mid-1;
		else l=mid+1;
	}
	return l;
}
int main()
{
	scanf("%d%lld",&n,&c),n1=(n<<1)-1,st[1]=0;
	for(int i=1;i<=n1;++i)scanf("%lld",&s[i]),s[i]+=s[i-1];
	for(int i=1;i<=n;++i)
	{
		for(;head<tail && to(st[head],i)<=to(st[head+1],i);++head);
		for(f[i]=to(st[head],i);head<tail && calc(st[tail-1],st[tail])>=calc(st[tail],i);--tail);
		st[++tail]=i;
	}
	return 0&printf("%lld",f[n]);
}