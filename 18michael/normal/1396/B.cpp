#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
int n,t,now,Test_num;
int a[2];
priority_queue<int,vector<int>,less<int> > pq;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch;do ch=getchar(),f|=(ch=='-');while(ch<'0' || ch>'9');
	do x=(x<<3)+(x<<1)+(ch^48),ch=getchar();while(ch>='0' && ch<='9');
	x=f? -x:x;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		while(!pq.empty())pq.pop();
		a[0]=a[1]=now=0,read(n);
		for(int i=1,x;i<=n;++i)read(x),pq.push(x);
		while(!pq.empty())
		{
			if(a[now]<pq.top())
			{
				t=0;
				if(a[now])t=a[now];
				a[now]=pq.top(),pq.pop();
				if(t)pq.push(t);
			}
			--a[now],now^=1;
		}
		if(a[now]<=a[now^1])now^=1;
		puts(now? "HL":"T");
	}
	return 0;
}