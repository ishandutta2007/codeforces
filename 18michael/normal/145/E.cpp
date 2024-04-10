#include<bits/stdc++.h>
using namespace std;
int n,m;
char c[1000002];
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
	int zero[4000002],one[4000002],laz[4000002],len[4000002];
	int mx[4000002][2];
	inline void build(int k,int l,int r)
	{
		len[k]=r-l+1;
		if(l==r){zero[k]=(c[l]=='4'),one[k]=(c[l]=='7'),mx[k][0]=mx[k][1]=1;return ;}
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		build(ls,l,mid),build(rs,mid+1,r),zero[k]=zero[ls]+zero[rs],one[k]=one[ls]+one[rs],mx[k][0]=max(mx[ls][0]+one[rs],zero[ls]+mx[rs][0]),mx[k][1]=max(one[ls]+mx[rs][1],mx[ls][1]+zero[rs]);
	}
	inline void modify(int k,int l,int r,int l1,int r1)
	{
		if(l>=l1 && r<=r1){laz[k]^=1,zero[k]=len[k]-zero[k],one[k]=len[k]-one[k],swap(mx[k][0],mx[k][1]);return ;}
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(laz[k])
		{
			laz[ls]^=1,zero[ls]=len[ls]-zero[ls],one[ls]=len[ls]-one[ls],swap(mx[ls][0],mx[ls][1]);
			laz[rs]^=1,zero[rs]=len[rs]-zero[rs],one[rs]=len[rs]-one[rs],swap(mx[rs][0],mx[rs][1]),laz[k]=0;
		}
		if(r1<=mid)modify(ls,l,mid,l1,r1);
		else if(l1>mid)modify(rs,mid+1,r,l1,r1);
		else modify(ls,l,mid,l1,mid),modify(rs,mid+1,r,mid+1,r1);
		zero[k]=zero[ls]+zero[rs],one[k]=one[ls]+one[rs],mx[k][0]=max(mx[ls][0]+one[rs],zero[ls]+mx[rs][0]),mx[k][1]=max(one[ls]+mx[rs][1],mx[ls][1]+zero[rs]);
	}
}S;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(n),read(m);
	for(int i=1;i<=n;++i)do c[i]=getchar();while(c[i]!='4' && c[i]!='7');
	S.build(1,1,n);
	for(int x,y;m--;)
	{
		scanf("%s",c);
		if(c[0]=='c')printf("%d\n",S.mx[1][0]);
		else read(x),read(y),S.modify(1,1,n,x,y);
	}
	return 0;
}