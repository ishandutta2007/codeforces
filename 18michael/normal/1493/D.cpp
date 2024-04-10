#include<cstdio>
#include<map>
#include<set>
#define Mx 200000
#define LL long long
#define mod 1000000007
using namespace std;
int n,q,p_t=0;
LL ans=1;
int p[200002],to[200002];
bool u[200002]={};
map<int,int> mp[200002];
multiset<int> st[200002];
inline void init()
{
	for(int i=2;i<=Mx;++i)
		if(!u[i])
		{
			p[++p_t]=i,to[i]=p_t;
			for(int j=i;j<=Mx/i;++j)u[j*i]=1;
		}
}
inline LL pow(LL a,int b)
{
	if(!b)return 1;
	if(b==1)return a;
	LL c=pow(a,(b>>1));
	c=(c*c)%mod;
	if(b&1)c=(c*a)%mod;
	return c;
}
inline void add(int x,int y)
{
	int t,t1,t2;
	for(int i=1;p[i]*p[i]<=y;++i)
		if(!(y%p[i]))
		{
			for(t=0;!(y%p[i]);y/=p[i],++t);
			t1=(st[i].size()==n? (*st[i].begin()):0);
			if(mp[x][i])st[i].erase(st[i].find(mp[x][i]));
			mp[x][i]+=t,st[i].insert(mp[x][i]);
			t2=(st[i].size()==n? (*st[i].begin()):0);
			ans=(ans*pow(p[i],t2-t1))%mod;
		}
	if(y>1)
	{
		t1=(st[to[y]].size()==n? (*st[to[y]].begin()):0);
		if(mp[x][to[y]])st[to[y]].erase(st[to[y]].find(mp[x][to[y]]));
		++mp[x][to[y]],st[to[y]].insert(mp[x][to[y]]);
		t2=(st[to[y]].size()==n? (*st[to[y]].begin()):0);
		ans=(ans*pow(y,t2-t1))%mod;
	}
}
int main()
{
	init(),scanf("%d%d",&n,&q);
	for(int i=1,x;i<=n;++i)scanf("%d",&x),add(i,x);
	for(int x,y;q--;)scanf("%d%d",&x,&y),add(x,y),printf("%lld\n",ans);
	return 0;
}