#include<bits/stdc++.h>
#define US unsigned int
using namespace std;
int n,m,t,q;
US sum,ans;
multiset<US> s2;
typedef pair<int,int> P;
set<P> s[100002];
set<P>::iterator it;
map<P,int> mp;
typedef tuple<US,int,int> T;
set<T> s1;
set<T>::iterator it1,it2;
inline bool find(int x,P p)
{
	int t=4;
	for(set<P>::iterator it=s[x].begin();it!=s[x].end() && (--t);++it)if((*it)==p)return 1;
	return 0;
}
inline void upd(int x,P p,bool o)
{
	int y,z;
	for(it=s[x].begin(),t=4,sum=0;it!=s[x].end() && (--t);++it)
	{
		sum+=(*it).first,y=x,z=(*it).second;
		if(y>z)swap(y,z);
		s1.erase(T((*it).first,y,z));
	}
	if(s[x].size()>2)s2.erase(sum);
	if(o)s[x].insert(p);
	else s[x].erase(p);
	for(it=s[x].begin(),t=4,sum=0;it!=s[x].end() && (--t);++it)
	{
		sum+=(*it).first,y=x,z=(*it).second;
		if(!find(z,P((*it).first,y)))continue;
		if(y>z)swap(y,z);
		s1.insert(T((*it).first,y,z));
	}
	if(s[x].size()>2)s2.insert(sum);
}
inline bool check(int a,int b,int c,int d)
{
	return a!=c && a!=d && b!=c && b!=d;
}
inline void calc()
{
	int i,j;
	for(ans=(s2.size()? (*s2.begin()):4294967295),it1=s1.begin(),i=7;it1!=s1.end() && (--i)>1;++it1)
		for(++(it2=it1),j=i;it2!=s1.end() && (--j);++it2)
			if(check(get<1>(*it1),get<2>(*it1),get<1>(*it2),get<2>(*it2)))
			{
				ans=min(ans,get<0>(*it1)+get<0>(*it2));
				break;
			}
	printf("%u\n",ans);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x,y,z;i<=m;++i)
	{
		scanf("%d%d%d",&x,&y,&z);
		if(x>y)swap(x,y);
		mp[P(x,y)]=z,upd(x,P(z,y),1),upd(y,P(z,x),1);
	}
	calc(),scanf("%d",&q);
	for(int o,x,y,z;q--;calc())
	{
		scanf("%d%d%d",&o,&x,&y);
		if(x>y)swap(x,y);
		if(!o)z=mp[P(x,y)],mp.erase(P(x,y)),upd(x,P(z,y),0),upd(y,P(z,x),0);
		else scanf("%d",&z),mp[P(x,y)]=z,upd(x,P(z,y),1),upd(y,P(z,x),1);
	}
	return 0;
}