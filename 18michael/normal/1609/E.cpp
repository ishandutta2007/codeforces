#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,q;
char c;
char s[100002];
struct Matrix
{
	LL a[3][3];
}M;
inline Matrix mul(Matrix a,Matrix b)
{
	Matrix c;
	for(int i=0;i<3;++i)
		for(int j=0;j<3;++j)
		{
			c.a[i][j]=inf;
			for(int k=0;k<3;++k)c.a[i][j]=min(c.a[i][j],a.a[i][k]+b.a[k][j]);
		}
	return c;
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
	Matrix m[400002];
	inline void modify(int k,int l,int r,int x)
	{
		if(l==r)
		{
			m[k]=M;
			return ;
		}
		int mid=((l+r)>>1),ls=lson(k),rs=rson(k);
		if(x<=mid)modify(ls,l,mid,x);
		else modify(rs,mid+1,r,x);
		m[k]=mul(m[rs],m[ls]);
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
	read(n),read(q),scanf("%s",s+1);
	for(int i=1;i<=n;++i)
	{
		M.a[0][0]=(s[i]=='a');
		M.a[0][1]=inf;
		M.a[0][2]=inf;
		M.a[1][0]=(s[i]=='b');
		M.a[1][1]=(s[i]=='b');
		M.a[1][2]=inf;
		M.a[2][0]=(s[i]=='c');
		M.a[2][1]=(s[i]=='c');
		M.a[2][2]=(s[i]=='c');
		S.modify(1,1,n,i);
	}
	for(int x;q--;)
	{
		read(x);
		do c=getchar();while(c!='a' && c!='b' && c!='c');
		s[x]=c;
		M.a[0][0]=(s[x]=='a');
		M.a[0][1]=inf;
		M.a[0][2]=inf;
		M.a[1][0]=(s[x]=='b');
		M.a[1][1]=(s[x]=='b');
		M.a[1][2]=inf;
		M.a[2][0]=(s[x]=='c');
		M.a[2][1]=(s[x]=='c');
		M.a[2][2]=(s[x]=='c');
		S.modify(1,1,n,x);
		M=S.m[1];
		printf("%lld\n",min(M.a[0][0],min(min(M.a[1][0],M.a[1][1]),min(M.a[2][0],min(M.a[2][1],M.a[2][2])))));
	}
	return 0;
}