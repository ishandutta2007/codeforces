#include<cstdio>
#include<map>
#define LL long long
using namespace std;
int n,k;
LL ans,mx,mn;
bool u;
LL a[100002];
map<LL,int> m;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline LL max(LL a,LL b)
{
	return a>b? a:b;
}
inline LL min(LL a,LL b)
{
	return a<b? a:b;
}
int main()
{
	ans=mx=mn=0,m.clear(),++m[0],read(n),read(k);
	for(int i=1;i<=n;++i)read(a[i]),a[i]+=a[i-1],mx=max(mx,a[i]),mn=min(mn,a[i]);
	mx-=mn;
	for(int i=1;i<=n;++i)
	{
		++m[a[i]],u=0;
		for(LL j=1;j<=mx;j*=k)
		{
			if(j==1)
			{
				if(u)break;
				u=1;
			}
			ans+=m[a[i]-j];
		}
	}
	printf("%lld",ans);
	return 0;
}