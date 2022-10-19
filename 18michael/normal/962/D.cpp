#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;
int n,t,k,k1,ans_t=0;
struct aaa
{
	LL val;
	int num;
}a[150002],ans[150002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(aaa a,aaa b)
{
	return a.val==b.val? (a.num<b.num):(a.val<b.val);
}
inline bool cmp1(aaa a,aaa b)
{
	return a.num<b.num? 1:0;
}
inline void swap(aaa &a,aaa &b)
{
	aaa c=a;a=b;b=c;
}
inline bool check(int x,int y)
{
	if(a[x].val>a[y].val || (a[x].val==a[y].val && a[x].num>a[y].num))
		return 1;
	return 0;
}
inline void clear(int x)
{
	while(1)
	{
		k=(x<<1),k1=(k|1);
		if(k>n)return ;
		if(k==n)
		{
			if(check(x,k))
				swap(a[x],a[k]);
			return ;
		}
		if(check(x,k))
		{
			if(check(k,k1))swap(a[x],a[k1]),x=k1;
			else swap(a[x],a[k]),x=k;
		}
		else if(check(x,k1))swap(a[x],a[k1]),x=k1;
		else return ;
	}
}
int main()
{
	read(n);
	for(int i=1;i<=n;++i)
		read(a[i].val),a[i].num=i;
	sort(a+1,a+n+1,cmp);
	while(n>=2)
	{
		if(n==2)
		{
			if(a[1].val==a[2].val)a[2].val<<=1,ans[++ans_t]=a[2];
			else ans[++ans_t]=a[1],ans[++ans_t]=a[2];
			break;
		}
		if(a[1].val==a[2].val)
		{
			if(a[1].val==a[3].val)
			{
				if(check(2,3))a[3].val<<=1,clear(3);
				else a[2].val<<=1,clear(2);
			}
			else a[2].val<<=1,clear(2);
		}
		else if(a[1].val==a[3].val)a[3].val<<=1,clear(3);
		else ans[++ans_t]=a[1];
		a[1]=a[n],--n,clear(1);
	}
	sort(ans+1,ans+ans_t+1,cmp1);
	printf("%d\n",ans_t);
	for(int i=1;i<=ans_t;++i)
		printf("%lld ",ans[i].val);
	return 0;
}