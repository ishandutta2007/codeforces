#include<bits/stdc++.h>
#define Mx 100000
#define LL long long
using namespace std;
int n,q,l,r,t,S_t=1;
LL ans;
int a[100002],m[100002],o[100002];
int rt[100002][2];
vector<int> Vec[100002];
struct SegTree
{
	int lson[4000002],rson[4000002];
	LL sum[4000002];
	inline void modify(int k,int k1,int l,int r,int x,int d)
	{
		sum[k]=sum[k1]+d;
		if(l==r)return ;
		int mid=((l+r)>>1);
		if(x<=mid)modify(lson[k]=(++S_t),lson[k1],l,mid,x,d),rson[k]=rson[k1];
		else modify(rson[k]=(++S_t),rson[k1],mid+1,r,x,d),lson[k]=lson[k1];
	}
	inline LL query(int k,int k1,int l,int r,int l1,int r1)
	{
		if(l>=l1 && r<=r1)return sum[k]-sum[k1];
		int mid=((l+r)>>1);
		if(r1<=mid)return query(lson[k],lson[k1],l,mid,l1,r1);
		if(l1>mid)return query(rson[k],rson[k1],mid+1,r,l1,r1);
		return query(lson[k],lson[k1],l,mid,l1,mid)+query(rson[k],rson[k1],mid+1,r,mid+1,r1);
	}
}S;
struct aaa
{
	int l,r,t;
	inline bool operator < (const aaa &a) const
	{
		return l<a.l;
	}
};
vector<aaa> vec;
set<aaa> s;
set<aaa>::iterator it;
inline void solve(aaa p)
{
	if(p.l<l)s.insert((aaa){p.l,l-1,p.t}),p.l=l;
	if(p.r>r)s.insert((aaa){r+1,p.r,p.t}),p.r=r;
	if(!(~p.t))ans+=min((LL)m[p.l],(LL)t*o[p.l]+a[p.l]);
	else p.t=min(t-p.t,Mx+1),ans+=S.query(rt[p.t][0],1,1,n,p.l,p.r)*p.t+S.query(rt[0][1],rt[p.t][1],1,n,p.l,p.r);
}
int main()
{
	scanf("%d",&n),rt[Mx+1][0]=rt[Mx+1][1]=1;
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d%d",&a[i],&m[i],&o[i]),s.insert((aaa){i,i,-1});
		if(o[i])Vec[m[i]/o[i]].push_back(i);
	}
	for(int i=Mx,x,y;~i;--i)
	{
		x=rt[i+1][0];
		for(int j=0;j<Vec[i].size();++j)S.modify(y=(++S_t),x,1,n,Vec[i][j],o[Vec[i][j]]),x=y;
		rt[i][0]=x,x=rt[i+1][1];
		for(int j=0;j<Vec[i].size();++j)S.modify(y=(++S_t),x,1,n,Vec[i][j],m[Vec[i][j]]),x=y;
		rt[i][1]=x;
	}
	for(scanf("%d",&q);q--;s.insert((aaa){l,r,t}),printf("%lld\n",ans))
	{
		scanf("%d%d%d",&t,&l,&r),ans=0,it=s.lower_bound((aaa){l,0,0}),vec.clear();
		if(it==s.end() || (*it).l>l)--it;
		for(;it!=s.end() && (*it).l<=r;it=s.erase(it))vec.push_back(*it);
		for(int i=0;i<vec.size();++i)solve(vec[i]);
	}
	return 0;
}