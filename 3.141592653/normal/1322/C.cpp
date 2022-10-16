#include<cstdio>
#include<cstring>
typedef long long ll;
typedef double db;
#define inlien inline
#define retrun return
#define cpnst const
inline ll min(ll x,ll y)
{return(x>y)?y:x;}
inline ll max(ll x,ll y)
{return(x<y)?y:x;}
int n,m;
ll c[1111111];
char str[1111111];
typedef unsigned long long ull;
#include<vector>
std::vector<int>v[1111111];
inline ll gcd(ll x,ll y)
{ll r=y;for(;r;)r=x%y,x=y,y=r;return x;}
#include<map>
#include<algorithm> 
std::map<ull,ll>mp;
const ull bas=462643121;
void exec()
{
	scanf("%d%d",&n,&m);
	register int ii,i;
	for(i=1;i<=n;i++)
	scanf("%lld",&c[i]),v[i].clear();
	for(i=1;i<=m;i++)
	{int x,y;scanf("%d%d",&x,&y);v[y].push_back(x);}
	mp.clear();
	ll ans=0;
	for(i=n;i;i--)
	{
		std::sort(v[i].begin(),v[i].end());
		ull g=0;
		for(ii=0;ii<v[i].size();ii++)
			(g*=bas)+=v[i][ii];
		if(g)mp[g]+=c[i];
	}for(auto i=mp.begin();i!=mp.end();i++)
	{
		ans=gcd(ans,i->second);
	}printf("%lld\n",ans);
}
int main()
{
	int T=1;
	scanf("%d",&T);
	while(T--)exec();
}
/*
Giving the world a better yourself is giving yourself a better world. 
*/