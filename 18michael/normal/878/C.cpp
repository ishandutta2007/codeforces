#include<bits/stdc++.h>
using namespace std;
int n,k;
struct aaa
{
	int siz;
	int mn[12],mx[12];
	inline bool operator < (const aaa &a) const
	{
		for(int i=0;i<k;++i)if(mx[i]>a.mn[i])return 0;
		return 1;
	}
}tmp;
set<aaa> s;
set<aaa>::iterator it;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<k;++j)scanf("%d",&tmp.mn[j]),tmp.mx[j]=tmp.mn[j];
		for(tmp.siz=1;(it=s.find(tmp))!=s.end();s.erase(it))
		{
			tmp.siz+=(*it).siz;
			for(int i=0;i<k;++i)tmp.mn[i]=min(tmp.mn[i],(*it).mn[i]),tmp.mx[i]=max(tmp.mx[i],(*it).mx[i]);
		}
		s.insert(tmp),printf("%d\n",(*(--(it=s.end()))).siz);
	}
	return 0;
}