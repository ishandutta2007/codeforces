#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
typedef long long LL;
const LL N=150005;
LL a1[N],a2[N],a3[N],a4[N];
LL n1,n2,n3,n4;
vector<LL> vec[5][N];
LL m1,m2,m3;
void Ins ()
{
	scanf("%lld%lld%lld%lld",&n1,&n2,&n3,&n4);
	for (LL u=1;u<=n1;u++)	scanf("%lld",&a1[u]);
	for (LL u=1;u<=n2;u++)	scanf("%lld",&a2[u]);
	for (LL u=1;u<=n3;u++)	scanf("%lld",&a3[u]);
	for (LL u=1;u<=n4;u++)	scanf("%lld",&a4[u]);
	scanf("%lld",&m1);
	for (LL u=1;u<=m1;u++)
	{
		LL x,y;
		scanf("%lld%lld",&x,&y);
		vec[2][y].push_back(x);
	}
	scanf("%lld",&m2);
	for (LL u=1;u<=m2;u++)
	{
		LL x,y;
		scanf("%lld%lld",&x,&y);
		vec[3][y].push_back(x);
	}
	scanf("%lld",&m3);
	for (LL u=1;u<=m3;u++)
	{
		LL x,y;
		scanf("%lld%lld",&x,&y);
		vec[4][y].push_back(x);
	}
}
multiset<LL> s;
multiset<LL> :: iterator it;
LL f[5][N];
void solve2()
{
	for (LL u=1;u<=n2;u++)
	{
		LL siz=vec[2][u].size();
		for (LL i=0;i<siz;i++)
		{
			LL x=vec[2][u][i];
			if (f[1][x]==-1) continue;
			it=s.find(f[1][x]);s.erase(it);
		}
		if (s.empty()) f[2][u]=-1;
		else f[2][u]=(*s.begin())+a2[u];
		for (LL i=0;i<siz;i++)
		{
			LL x=vec[2][u][i];
			if (f[1][x]==-1) continue;
			s.insert(f[1][x]);
		}
	}
	s.clear();
	for (LL u=1;u<=n2;u++) if (f[2][u]!=-1) s.insert(f[2][u]);
}
void solve3 ()
{
	for (LL u=1;u<=n3;u++)
	{
		LL siz=vec[3][u].size();
		for (LL i=0;i<siz;i++)
		{
			LL x=vec[3][u][i];
			if (f[2][x]==-1) continue;
			it=s.find(f[2][x]);s.erase(it);
		}
		if (s.empty()) f[3][u]=-1;
		else f[3][u]=(*s.begin())+a3[u];
		for (LL i=0;i<siz;i++)
		{
			LL x=vec[3][u][i];
			if (f[2][x]==-1) continue;
			s.insert(f[2][x]);
		}
	}
	s.clear();
	for (LL u=1;u<=n3;u++) if (f[3][u]!=-1) s.insert(f[3][u]);
}
void solve4 ()
{
	for (LL u=1;u<=n4;u++)
	{
		LL siz=vec[4][u].size();
		for (LL i=0;i<siz;i++)
		{
			LL x=vec[4][u][i];
			if (f[3][x]==-1) continue;
			it=s.find(f[3][x]);s.erase(it);
		}
		if (s.empty()) f[4][u]=-1;
		else f[4][u]=(*s.begin())+a4[u];
		for (LL i=0;i<siz;i++)
		{
			LL x=vec[4][u][i];
			if (f[3][x]==-1) continue;
			s.insert(f[3][x]);
		}
	}
	LL ans=-1;
	for (LL u=1;u<=n4;u++) if (f[4][u]!=-1)
	{
		if (ans==-1) ans=f[4][u];
		else ans=min(ans,f[4][u]);
	}
	printf("%lld\n",ans);
}
int main()
{
	Ins();
	for (LL u=1;u<=n1;u++) f[1][u]=a1[u];
	for (LL u=1;u<=n1;u++) s.insert(f[1][u]);
	solve2();
	solve3();
	solve4();
	return 0;
}