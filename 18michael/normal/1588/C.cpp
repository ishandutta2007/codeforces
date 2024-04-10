#include<bits/stdc++.h>
#define LL long long
#define Mx 300000
using namespace std;
int n,Test_num;LL res,cnt,ans=0;
int a[300002],id[300002];
LL pre[300002],XR[300002],val[300002];
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
	LL xr[1200008];
	inline void build(int k,int l,int r)
	{
		xr[k]=0;if(l==r)return ;
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		build(ls,l,mid),build(rs,mid+1,r);
	}
	inline void modify(int k,int l,int r,int x,LL d)
	{
		if(l==r){xr[k]=d;return ;}
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(x<=mid)modify(ls,l,mid,x,d);
		else modify(rs,mid+1,r,x,d);
		xr[k]=(xr[ls]^xr[rs]);
	}
	inline LL query(int k,int l,int r,int l1,int r1)
	{
		if(l1>r1)return 0;
		if(l>=l1 && r<=r1)return xr[k];
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(r1<=mid)return query(ls,l,mid,l1,r1);
		if(l1>mid)return query(rs,mid+1,r,l1,r1);
		return (query(ls,l,mid,l1,mid)^query(rs,mid+1,r,mid+1,r1));
	}
}S;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(int x,int y)
{
	return pre[x]==pre[y]? (x<y):(pre[x]<pre[y]);
}
inline LL RND()
{
	LL res=rand();
	res*=rand(),res^=rand();
	res*=rand(),res^=rand();
	res*=rand(),res^=rand();
	res*=rand(),res^=rand();
	return res>0? res:-res;
}
int main()
{
	srand(time(NULL)),read(Test_num);
	for(int i=0;i<=Mx;++i)val[i]=RND();
	for(int i=2;i<=Mx;++i)XR[i]=(XR[i-2]^val[i]);
	while(Test_num--)
	{
		read(n),ans=id[0]=0,S.build(1,0,n);
		for(int i=1;i<=n;++i)read(a[i]),pre[i]=pre[i-1]+(i&1? a[i]:-a[i]),id[i]=i;
		sort(id,id+n+1,cmp);
		//for(int i=0;i<=n;++i)printf("%lld%c",pre[i],i==n? '\n':' ');
		for(int i=0,j;i<=n;i=j)
		{
			for(j=i,cnt=0;j<=n && pre[id[j]]==pre[id[i]];++j)S.modify(1,0,n,id[j],val[id[j]]);
			//printf(" i:%d j:%d\n",i,j);
			for(int k=i+1,l;k<j;++k)
			{
				res=S.query(1,0,n,id[k-1]+1,id[k]-1),l=id[k]-1-(((id[k]-1-id[k-1])>>1)<<1);
				while(l>id[k-1])l-=2;
				//printf("  res:%lld id[k-1]:%d id[k]:%d l:%d\n",res,id[k-1],id[k],l);
				if(res==((id[k]-1>=0? XR[id[k]-1]:0)^(l>=0? XR[l]:0)))++cnt,ans+=cnt;
				else
				{
					for(--l;l+2<=id[k-1];l+=2);
					if(res==((id[k]-2>=0? XR[id[k]-2]:0)^(l>=0? XR[l]:0)))++cnt,ans+=cnt;
					else cnt=0;
				}
				//printf("  k:%d cnt:%lld\n",k,cnt);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
1
4
1 1 1 1
*/