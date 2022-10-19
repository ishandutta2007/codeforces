#include<bits/stdc++.h>
#define Mx 15000000
using namespace std;
int n,p_t=0,ans=0,t=0;
int a[300002],cnt[15000002],p[15000002],to[15000002];
bool u[15000002]={};
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline int gcd(int x,int y)
{
	return y? gcd(y,(x%y)):x;
}
inline void init()
{
	for(int i=2;i<=Mx;++i)
		if(!u[i])
		{
			p[++p_t]=i,to[i]=p_t;
			for(int j=i;j<=Mx/i;++j)u[j*i]=1;
		}
}
inline void work(int x)
{
	for(int i=1;p[i]*p[i]<=x;++i)
		if(!(x%p[i]))
		{
			++cnt[i];
			do x/=p[i];while(!(x%p[i]));
		}
	if(x>1)++cnt[to[x]];
}
int main()
{
	init(),read(n);
	for(int i=1;i<=n;++i)read(a[i]),t=gcd(t,a[i]);
	for(int i=1;i<=n;++i)work(a[i]/t);
	for(int i=1;i<=p_t;++i)ans=max(ans,cnt[i]);
	printf("%d",ans? (n-ans):-1);
	return 0;
}