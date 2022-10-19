#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f
using namespace std;
int n,k,Test_num,t;
LL ans;
int a[200002],id[200002];
bool u[200002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
struct aaa
{
	int mn,pos;
};
inline aaa merge(aaa a,aaa b)
{
	return a.mn<b.mn? a:b;
}
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
	aaa A[800002];
	int laz[800002];
	inline void build(int k,int l,int r)
	{
		laz[k]=0;
		if(l==r)return (void)(A[k]=(aaa){-l-a[l],l});
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		build(ls,l,mid),build(rs,mid+1,r),A[k]=merge(A[ls],A[rs]);
	}
	inline void add(int k,int l,int r,int l1,int r1,int d)
	{
		if(l>=l1 && r<=r1)return (void)(A[k].mn+=d,laz[k]+=d);
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(laz[k])A[ls].mn+=laz[k],laz[ls]+=laz[k],A[rs].mn+=laz[k],laz[rs]+=laz[k],laz[k]=0;
		if(r1<=mid)add(ls,l,mid,l1,r1,d);
		else if(l1>mid)add(rs,mid+1,r,l1,r1,d);
		else add(ls,l,mid,l1,mid,d),add(rs,mid+1,r,mid+1,r1,d);
		A[k]=merge(A[ls],A[rs]);
	}
}S;
inline bool cmp(int x,int y)
{
	return a[x]+x>a[y]+y;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),read(k),ans=t=0;
		for(int i=1;i<=n;++i)read(a[i]),ans+=a[i],u[i]=0,id[i]=i;
		/*S.build(1,1,n);
		for(int i=1,x;i<=k;++i)ans+=n-k+S.A[1].mn,printf("ans+=%d-%d+%d=%d -> %lld\n",2*n,k,S.A[1].mn,2*n-k+S.A[1].mn,ans),
		x=S.A[1].pos,S.add(1,1,n,x,x,inf),S.add(1,1,n,x,n,-1);*/
		sort(id+1,id+n+1,cmp);
		for(int i=1;i<=k;++i)ans-=a[id[i]],u[id[i]]=1;
		for(int i=1;i<=n;++i)
		{
			if(u[i])++t;
			else ans+=t;
		}
		printf("%lld\n",ans);
		
	}
	return 0;
}