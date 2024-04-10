#include<bits/stdc++.h>
using namespace std;
int n,las,Test_num,tot;
int la[200002],nx[200002],cnt[26];
char s[200002];
typedef pair<int,int> P;
P p,p1;
set<P,greater<P> > s1;
set<P> st[26];
vector<P> vec;
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
	int sum[800002],laz[800002];
	inline void cover(int k,int l,int r,int l1,int r1,int d)
	{
		if(l>=l1 && r<=r1)return (void)(sum[k]=(laz[k]=d)*(r-l+1));
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(~laz[k])sum[ls]=(laz[ls]=laz[k])*(mid-l+1),sum[rs]=(laz[rs]=laz[k])*(r-mid),laz[k]=-1;
		if(l1<=mid)cover(ls,l,mid,l1,r1,d);
		if(r1>mid)cover(rs,mid+1,r,l1,r1,d);
		sum[k]=sum[ls]+sum[rs];
	}
	inline int query(int k,int l,int r,int l1,int r1)
	{
		if(l>=l1 && r<=r1)return sum[k];
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(~laz[k])sum[ls]=(laz[ls]=laz[k])*(mid-l+1),sum[rs]=(laz[rs]=laz[k])*(r-mid),laz[k]=-1;
		if(r1<=mid)return query(ls,l,mid,l1,r1);
		if(l1>mid)return query(rs,mid+1,r,l1,r1);
		return query(ls,l,mid,l1,r1)+query(rs,mid+1,r,l1,r1);
	}
}S;
inline void Link(int x,int y)
{
	nx[x]=y,la[y]=x;
	if(x && y<=n && s[x]!=s[y])st[s[x]].insert(P(x,y)),st[s[y]].insert(P(x,y));
}
inline void del(int x)
{
	if(la[x])st[s[la[x]]].erase(P(la[x],x)),st[s[x]].erase(P(la[x],x));
	if(nx[x])st[s[x]].erase(P(x,nx[x])),st[s[nx[x]]].erase(P(x,nx[x]));
}
inline int find(int x)
{
	for(;(++x)<=n;)if(S.query(1,1,n,x,x))break;
	return x;
}
inline void solve()
{
	scanf("%s",s+1),n=strlen(s+1),S.cover(1,1,n,1,n,1),las=tot=0,s1.clear(),vec.clear();
	for(int i=0;i<26;++i)cnt[i]=0,st[i].clear();
	for(int i=1;i<=n;++i)s[i]-='a';
	for(int i=1;i<n;++i)if(s[i]==s[i+1])Link(las,i),las=i,++cnt[s[i]],++tot;
	for(int i=0;i<26;++i)if(cnt[i])s1.insert(P(cnt[i],i));
	for(Link(las,n+1);s1.size()>1;)
	{
		p=(*s1.begin()),p1=(*st[p.second].begin()),vec.push_back(P(S.query(1,1,n,1,p1.first+1),S.query(1,1,n,1,p1.second))),S.cover(1,1,n,p1.first+1,p1.second,0),del(p1.first),del(p1.second),Link(la[p1.first],nx[p1.second]),s1.erase(P(cnt[s[p1.first]],s[p1.first])),s1.erase(P(cnt[s[p1.second]],s[p1.second]));
		if(--cnt[s[p1.first]])s1.insert(P(cnt[s[p1.first]],s[p1.first]));
		if(--cnt[s[p1.second]])s1.insert(P(cnt[s[p1.second]],s[p1.second]));
	}
	for(int i=las=find(0),j;i<=n;i=j)if((j=find(i))>n || s[i]==s[j])vec.push_back(P(S.query(1,1,n,1,las),S.query(1,1,n,1,i))),S.cover(1,1,n,las,i,0),las=j;
	printf("%d\n",vec.size());
	for(int i=0;i<vec.size();++i)printf("%d %d\n",vec[i].first,vec[i].second);
}
int main()
{
	for(scanf("%d",&Test_num);Test_num--;)solve();
	return 0;
}