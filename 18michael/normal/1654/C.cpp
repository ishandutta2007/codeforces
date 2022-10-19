#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,Test_num,ok,t;
LL sum;
LL a[1000002];
priority_queue<LL,vector<LL>,less<LL> > pq,ept;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline bool cmp(LL x,LL y)
{
	return x>y;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),pq=ept,ok=1,sum=0,t=1;
		for(int i=1;i<=n;++i)read(a[i]),sum+=a[i];
		sort(a+1,a+n+1,cmp),pq.push(sum);
		while(!pq.empty())
		{
			LL x=pq.top();pq.pop();
			if(a[t]==x)
			{
				++t;
				continue;
			}
			if(a[t]>x)
			{
				ok=0;
				break;
			}
			pq.push(x/2),pq.push((x+1)/2);
		}
		puts(ok? "YES":"NO");
	}
	return 0;
}