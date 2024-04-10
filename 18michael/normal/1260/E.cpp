#include<cstdio>
#include<queue>
#define LL long long
#define inf 0x3f3f3f3f
using namespace std;
int n,t,la;LL ans=0;int a[(1<<18)+2];
priority_queue<int,vector<int>,greater<int> > pq;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch;do ch=getchar(),f|=(ch=='-');while(ch<'0' || ch>'9');
	do x=(x<<3)+(x<<1)+(ch^48),ch=getchar();while(ch>='0' && ch<='9');
	x=f? -x:x;
}
int main()
{
	read(n),la=n;
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1;i<=n;++i)
		if(a[i]==-1)
		{
			for(int j=1;j<i;++j)a[j]=0;
			break;
		}
	for(int i=1;i<=18;++i)if((1<<i)==n){t=i;break;}
	if(a[la]!=-1)pq.push(a[la]);
	else pq.push(a[--la]);--la;
	for(int i=t;i;--i)
	{
		ans+=pq.top(),pq.pop();
		for(int j=(1<<(i-1));j;--j)
		{
			if(a[la]!=-1)pq.push(a[la]);
			else ++j;--la;
		}
	}
	printf("%lld",ans);
	return 0;
}