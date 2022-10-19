#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
int n,t=0;
int X[200002],Y[200002],id[200002],to[200002];
char ch[200002][7];
set<int> s[200002];
set<int>::iterator it;
typedef pair<int,int> P;P p;
inline int lson(int x)
{
	return (x<<1);
}
inline int rson(int x)
{
	return ((x<<1)|1);
}
struct SegTree
{
	int sum[800002],mx[800002];
	inline void modify(int k,int l,int r,int x,int y,int d)
	{
		sum[k]+=d;
		if(l==r)
		{
			if(d>0)s[x].insert(y);
			else s[x].erase(y);
			if((it=s[x].end())!=s[x].begin())mx[k]=(*(--it));
			else mx[k]=0;
			return ;
		}
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(x<=mid)modify(ls,l,mid,x,y,d);
		else modify(rs,mid+1,r,x,y,d);
		mx[k]=max(mx[ls],mx[rs]);
	}
	inline bool query(int k,int l,int r,int x,int y)
	{
		if(l==r)
		{
			if(mx[k]<=y)return 0;
			p=P(to[l],(*s[l].upper_bound(y)));
			return 1;
		}
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(x<mid && mx[ls]>y && query(ls,l,mid,x,y))return 1;
		return query(rs,mid+1,r,x,y);
	}
}S;
inline bool cmp(int x,int y)
{
	return X[x]<X[y]? 1:0;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%s%d%d",ch[i],&X[i],&Y[i]),id[i]=i;
	sort(id+1,id+n+1,cmp);
	for(int i=1;i<=n;++i)
	{
		if(i==1 || X[id[i]]!=to[t])to[++t]=X[id[i]];
		X[id[i]]=t;
	}
	for(int i=1;i<=n;++i)
	{
		if(ch[i][0]=='f')
		{
			if(!S.query(1,1,n,X[i],Y[i]))puts("-1");
			else printf("%d %d\n",p.first,p.second);
		}
		else S.modify(1,1,n,X[i],Y[i],(ch[i][0]=='a'? 1:-1));
	}
	return 0;
}