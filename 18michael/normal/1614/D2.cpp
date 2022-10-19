#include<bits/stdc++.h>
#define Mx 20000000
#define LL long long
using namespace std;
int n,p_t=0;
int cnt[20000002],p[20000002];
LL f[20000002];
bool u[20000002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void init()
{
	for(int i=2;i<=Mx;++i)
	{
		if(!u[i])p[++p_t]=i;
		for(int j=1;j<=p_t && p[j]<=Mx/i;++j)
		{
			u[p[j]*i]=1;
			if(!(i%p[j]))break;
		}
	}
}
int main()
{
	init(),read(n);
	for(int i=1,x;i<=n;++i)read(x),++cnt[x];
	for(int i=1;i<=Mx;++i)
		for(int j=2*i;j<=Mx;j+=i)
			cnt[i]+=cnt[j];
		//for(int j=1;j<=p_t && p[j]*i<=Mx;++j)
			//cnt[i]+=cnt[p[j]*i];
	for(int i=Mx;i;--i)
	{
		f[i]=1LL*cnt[i]*i;
		for(int j=1;j<=p_t && p[j]*i<=Mx;++j)
			f[i]=max(f[i],f[p[j]*i]+1LL*(cnt[i]-cnt[p[j]*i])*i);
	}
	return 0&printf("%lld",f[1]);
}