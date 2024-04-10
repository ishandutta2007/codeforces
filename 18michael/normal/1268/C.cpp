#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n;LL res=0,res1=0,res2=0;
int a[200002],arr[200002]={},p[200002]={};
priority_queue<int,vector<int>,less<int> > pq;
priority_queue<int,vector<int>,greater<int> > pq1;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline int lowbit(int x)
{
	return x&(-x);
}
inline void modify(int x)
{
	while(x<=n)++arr[x],x+=lowbit(x);
}
inline int query(int x)
{
	int res=0;
	while(x)res+=arr[x],x-=lowbit(x);
	return res;
}
int main()
{
	read(n);
	for(int i=1;i<=n;++i)read(a[i]),p[a[i]]=i;
	for(LL i=1;i<=n;++i)
	{
		modify(p[i]),res+=i-query(p[i]),res2+=p[i];
		if(pq.size()==pq1.size())
		{
			if(pq1.empty() || p[i]<pq1.top())pq.push(p[i]),res1+=p[i];
			else pq.push(pq1.top()),res1+=pq1.top(),pq1.pop(),pq1.push(p[i]);
		}
		else
		{
			if(p[i]>pq.top())pq1.push(p[i]);
			else pq1.push(pq.top()),res1-=pq.top(),pq.pop(),pq.push(p[i]),res1+=p[i];
		}
		printf("%lld ",res-res1+(res2-res1)+(i&1)*pq.top()-(i/2)*((i+1)/2));
	}
	return 0;
}