#include<cstdio>
#include<algorithm>
using namespace std;
int n,n1=0,d,c_t=0,t=0,l,r,mid;
int s[500002],a[500002],c[1000002],id[1000002],A[500002],S[500002],id1[500002];
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
	int mx[4000002];
	inline void modify(int k,int l,int r,int x,int d)
	{
		if(l==r){mx[k]=max(mx[k],d);return ;}
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(x<=mid)modify(ls,l,mid,x,d);
		else modify(rs,mid+1,r,x,d);
		mx[k]=max(mx[ls],mx[rs]);
	}
	inline int query(int k,int l,int r,int x)
	{
		if(l>=x)return mx[k];
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(x>mid)return query(rs,mid+1,r,x);
		return max(query(ls,l,mid,x),mx[rs]);
	}
}ST;
inline bool cmp(int x,int y)
{
	return c[x]<c[y]? 1:0;
}
inline bool cmp1(int x,int y)
{
	return S[x]<S[y]? 1:0;
}
inline bool cmp2(int x,int y)
{
	return s[x]>s[y]? 1:0;
}
int main()
{
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&s[i],&a[i]);
		if(s[i]<d)--i,--n;
		else c[++c_t]=s[i],id[c_t]=c_t,c[++c_t]=a[i],id[c_t]=c_t;
	}
	sort(id+1,id+c_t+1,cmp),c[0]=-1;
	for(int i=1;i<=c_t;++i)
	{
		if(c[id[i]]!=c[id[i-1]])++t;
		if(id[i]&1)s[(id[i]+1)/2]=t;
		else a[id[i]/2]=t;
	}
	for(int i=1;i<=n;++i)
	{
		if(a[i]<=s[i])A[++n1]=a[i],S[n1]=s[i],id[n1]=n1;
		else a[i-n1]=a[i],s[i-n1]=s[i],id1[i-n1]=i-n1;
	}
	n-=n1,sort(id+1,id+n1+1,cmp1),sort(id1+1,id1+n+1,cmp2);
	for(int i=2;i<=n1;++i)A[id[i]]=max(A[id[i]],A[id[i-1]]);
	for(int i=1;i<=n;++i)
	{
		for(l=1,r=n1;l<=r;)
		{
			mid=((l+r)>>1);
			if(A[id[mid]]<=s[id1[i]])l=mid+1;
			else r=mid-1;
		}
		if(r==n1 || a[id1[i]]<=S[id[r+1]])ST.modify(1,1,t,s[id1[i]],ST.query(1,1,t,a[id1[i]])+1);
	}
	return 0&printf("%d",n1+ST.mx[1]);
}