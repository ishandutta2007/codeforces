#include<cstdio>
#include<map>
using namespace std;
map<long long,long long>t;
int q;
inline int dep(long long x)
{
	int cnt=0;
	while(x)x/=2,cnt++;
	return cnt;
}
inline void modify(long long u,long long v,int w)
{
	long long d1=dep(u),d2=dep(v);
	while(d1>d2)t[u]+=w,u/=2,d1--;
	while(d2>d1)t[v]+=w,v/=2,d2--;
	while(u!=v)t[u]+=w,t[v]+=w,u/=2,v/=2,d1--,d2--;
}
inline long long query(long long u,long long v)
{
	long long ans=0,d1=dep(u),d2=dep(v);
	while(d1>d2)ans+=t[u],u/=2,d1--;
	while(d2>d1)ans+=t[v],v/=2,d2--;
	while(u!=v)ans+=t[u]+t[v],u/=2,v/=2,d1--,d2--;
	return ans;
}
int main()
{
	scanf("%d",&q);
	while(q--)
	{
		int kase;
		scanf("%d",&kase);
		if(kase==1)
		{
			long long u,v,w;
			scanf("%lld%lld%lld",&u,&v,&w);
			modify(u,v,w);
		}
		if(kase==2)
		{
			long long u,v;
			scanf("%lld%lld",&u,&v);
			printf("%lld\n",query(u,v));
		}
	}
	return 0;
}