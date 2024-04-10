#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
const int N=200005;
multiset<ll> st[N],St;
int n,q,f[N],d[N],i,j;
ll t[N],s[N];
void cirno(int x)
{
	if(st[x].empty())
		return;
	ll w=t[x]/(d[x]+2);
	St.erase(St.find(w+*(st[x].begin())));
	St.erase(St.find(w+*(--(st[x].end()))));
}
void baka(int x)
{
	if(st[x].empty())
		return;
	ll w=t[x]/(d[x]+2);
	St.insert(w+*(st[x].begin()));
	St.insert(w+*(--(st[x].end())));
}
int main()
{
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;++i)
		scanf("%lld",t+i);
	for(i=1;i<=n;++i)
	{
		scanf("%d",f+i);
		d[f[i]]++;
	}
	for(i=1;i<=n;++i)
	{
		s[f[i]]+=t[i]/(d[i]+2);
		s[i]+=t[i]-t[i]/(d[i]+2)*(d[i]+1);
	}
	for(i=1;i<=n;++i)
		st[f[i]].insert(s[i]);
	for(i=1;i<=n;++i)
	if(!st[i].empty())
	{
		St.insert((*st[i].begin())+t[i]/(d[i]+2));
		St.insert((*(--st[i].end()))+t[i]/(d[i]+2));
	}
	while(q--)
	{
		scanf("%d",&i);
		if(i==1)
		{
			scanf("%d%d",&i,&j);
			cirno(f[i]),cirno(f[f[i]]),cirno(f[f[f[i]]]);
			st[f[i]].erase(st[f[i]].find(s[i]));
			st[f[f[i]]].erase(st[f[f[i]]].find(s[f[i]]));
			st[f[f[f[i]]]].erase(st[f[f[f[i]]]].find(s[f[f[i]]]));
			s[f[i]]-=t[i]/(d[i]+2);
			s[f[i]]-=t[f[i]]-t[f[i]]/(d[f[i]]+2)*(d[f[i]]+1);
			s[f[f[i]]]-=t[f[i]]/(d[f[i]]+2);
			--d[f[i]];
			s[f[i]]+=t[f[i]]-t[f[i]]/(d[f[i]]+2)*(d[f[i]]+1);
			s[f[f[i]]]+=t[f[i]]/(d[f[i]]+2);
			st[f[f[i]]].insert(s[f[i]]);
			st[f[f[f[i]]]].insert(s[f[f[i]]]);
			baka(f[i]),baka(f[f[i]]),baka(f[f[f[i]]]);
			f[i]=j;
			cirno(f[i]),cirno(f[f[i]]),cirno(f[f[f[i]]]);
			st[f[f[i]]].erase(st[f[f[i]]].find(s[f[i]]));
			st[f[f[f[i]]]].erase(st[f[f[f[i]]]].find(s[f[f[i]]]));
			s[f[i]]-=t[f[i]]-t[f[i]]/(d[f[i]]+2)*(d[f[i]]+1);
			s[f[f[i]]]-=t[f[i]]/(d[f[i]]+2);
			++d[f[i]];
			s[f[i]]+=t[i]/(d[i]+2);
			s[f[i]]+=t[f[i]]-t[f[i]]/(d[f[i]]+2)*(d[f[i]]+1);
			s[f[f[i]]]+=t[f[i]]/(d[f[i]]+2);
			st[f[f[i]]].insert(s[f[i]]);
			st[f[f[f[i]]]].insert(s[f[f[i]]]);
			st[f[i]].insert(s[i]);
			baka(f[i]),baka(f[f[i]]),baka(f[f[f[i]]]);
		}
		else if(i==2)
		{
			scanf("%d",&i);
			printf("%lld\n",s[i]+t[f[i]]/(d[f[i]]+2));
		}
		else
			printf("%lld %lld\n",*(St.begin()),*(--St.end()));
	}
	return 0;
}