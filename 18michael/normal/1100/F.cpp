#include<cstdio>
#include<algorithm>
#define Mx 19
using namespace std;
int n,q,t=1;
int c[500002],id[500002];
struct aaa
{
	int a[22],num[22];
	inline void insert(int x,int y)
	{
		for(int i=Mx;~i;--i)
			if((x>>i)&1)
			{
				if(num[i]<y)swap(a[i],x),swap(num[i],y);
				if(a[i])x^=a[i],y=min(y,num[i]);
			}
	}
	inline int calc(int l)
	{
		int x=0;
		for(int i=Mx;~i;--i)if(!((x>>i)&1) && num[i]>=l)x^=a[i];
		return x;
	}
}S;
struct bbb
{
	int l,r,ans;
}qry[500002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(int x,int y)
{
	return qry[x].r<qry[y].r? 1:0;
}
int main()
{
	read(n);for(int i=1;i<=n;++i)read(c[i]);
	read(q);for(int i=1;i<=q;++i)read(qry[i].l),read(qry[i].r),id[i]=i;
	sort(id+1,id+q+1,cmp);
	for(int i=1;i<=q;++i)
	{
		while(t<=qry[id[i]].r)S.insert(c[t],t),++t;
		qry[id[i]].ans=S.calc(qry[id[i]].l);
	}
	for(int i=1;i<=q;++i)printf("%d\n",qry[i].ans);
	return 0;
}