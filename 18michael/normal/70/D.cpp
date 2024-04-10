#include<bits/stdc++.h>
#define LL long long
using namespace std;
int q;
struct Vec
{
	int x,y;
	inline bool operator < (const Vec a) const
	{
		return x==a.x? (y<a.y):(x<a.x);
	}
};
inline Vec mns(Vec a,Vec b)
{
	return (Vec){a.x-b.x,a.y-b.y};
}
inline LL cross(Vec a,Vec b)
{
	return (LL)a.x*b.y-(LL)a.y*b.x;
}
set<Vec>::iterator it,it1;
struct Convex_Hull
{
	set<Vec> s;
	inline void insert(Vec v)
	{
		if(s.count(v))return ;
		it=s.lower_bound(v);
		if(it!=s.end() && it!=s.begin() && cross(mns(*(--(it1=it)),v),mns(*it,v))<=0)return ;
		while(it!=s.end() && (++(it1=it))!=s.end() && cross(mns(v,*it),mns(*it1,*it))<=0)it=s.erase(it);
		while(it!=s.begin() && (it1=(--it))!=s.begin() && cross(mns(*(--it1),*it),mns(v,*it))<=0)it=s.erase(it);
		s.insert(v);
	}
	inline bool query(Vec v)
	{
		if(s.count(v))return 1;
		it=s.lower_bound(v);
		return (it!=s.end() && it!=s.begin() && cross(mns(*(--(it1=it)),v),mns(*it,v))<=0);
	}
}U,D;
int main()
{
	scanf("%d",&q);
	for(int o,x,y;q--;)
	{
		scanf("%d%d%d",&o,&x,&y);
		if(o==1)U.insert((Vec){x,y}),D.insert((Vec){-x,-y});
		else puts((U.query((Vec){x,y}) && D.query((Vec){-x,-y}))? "YES":"NO");
	}
	return 0;
}