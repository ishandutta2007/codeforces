#include<bits/stdc++.h>
#define Mx 2002
using namespace std;
int n,m,q;
int cnt[Mx];
bitset<Mx> tmp;
bitset<Mx> bs[Mx];
struct cmp
{
	inline bool operator () (const int &a,const int &b) const
	{
		return cnt[a]==cnt[b]? (a<b):(cnt[a]<cnt[b]);
	}
};
set<int,cmp> s;
set<int,cmp>::iterator it,it1,it2;
typedef pair<int,int> P;
set<P> ans;
inline bool check(int x,int y)
{
	return (bs[x]&bs[y])!=bs[y];
}
inline void ins(int x)
{
	s.insert(x),it=s.lower_bound(x);
	if(it!=s.begin() && check(*it,*(--(it1=it))))ans.insert(P(*it,*it1));
	if((++(it2=it))!=s.end() && check(*it2,*it))ans.insert(P(*it2,*it));
	if(it2!=s.end() && it!=s.begin() && check(*it2,*it1))ans.erase(P(*it2,*it1));
}
inline void del(int x)
{
	it=s.lower_bound(x);
	if(it!=s.begin() && check(*it,*(--(it1=it))))ans.erase(P(*it,*it1));
	if((++(it2=it))!=s.end() && check(*it2,*it))ans.erase(P(*it2,*it));
	if(it2!=s.end() && it!=s.begin() && check(*it2,*it1))ans.insert(P(*it2,*it1));
	s.erase(x);
}
inline void print(int x,int y,int z,int w)
{
	if(x>z)swap(x,z);
	if(y>w)swap(y,w);
	printf("%d %d %d %d\n",x,y,z,w);
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;++i)ins(i);
	for(int x,y,z;q--;)
	{
		scanf("%d%d%d",&x,&y,&z),tmp.set(),tmp>>=(Mx-z+y-1),tmp<<=y,del(x),cnt[x]=(bs[x]^=tmp).count(),ins(x);
		if(!ans.size())puts("-1");
		else x=(*ans.begin()).first,y=(*ans.begin()).second,print(x,(bs[x]&(~bs[y]))._Find_first(),y,((~bs[x])&bs[y])._Find_first());
	}
	return 0;
}