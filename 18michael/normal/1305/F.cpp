#include<bits/stdc++.h>
#define Mx 1000000
#define LL long long
using namespace std;
int n,p_t=0;
LL ans;
int p[1000002];
LL a[200002];
bool u[1000002],vis[200002];
set<LL> s;
set<LL>::iterator it;
inline int RND()
{
	int x=rand();
	x*=rand(),x^=rand();
	x*=rand(),x^=rand();
	return x>0? x:-x;
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
inline void ins(LL x)
{
	if(!x)return ;
	for(int i=1;i<=p_t;++i)if(!(x%p[i]))for(s.insert(p[i]);!(x%p[i]);x/=p[i]);
	if(x>1)s.insert(x);
}
inline LL check(LL x)
{
	LL res=0;
	for(int i=1;i<=n;++i)res+=min(a[i]>=x? a[i]%x:n,x-(a[i]%x));
	return res;
}
int main()
{
	init(),scanf("%d",&n),ans=n;
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	for(int i=1,x;i<=min(n,50);++i)
	{
		do x=RND()%n+1;while(vis[x]);
		vis[x]=1,ins(a[x]-1),ins(a[x]),ins(a[x]+1);
	}
	for(it=s.begin();it!=s.end();++it)ans=min(ans,check(*it));
	return 0&printf("%lld",ans);
}