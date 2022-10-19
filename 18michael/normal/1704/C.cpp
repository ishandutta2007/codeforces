#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,m,t,ans,Test_num;
int a[1000002];
priority_queue<int,vector<int> > pq;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(Test_num);
	while(Test_num--)
	{
		read(n),read(m),ans=0;
		for(int i=1;i<=m;++i)read(a[i]);
		sort(a+1,a+m+1);
		for(int i=1;i<m;++i)pq.push(a[i+1]-a[i]-1);
		pq.push(n+a[1]-a[m]-1),t=0;
		for(;pq.size();)
		{
			if(pq.top()-t>1)ans+=pq.top()-t-1;
			else ans+=max(pq.top()-t,0);
			t+=4;
			pq.pop();
		}
		printf("%d\n",n-ans);
	}
	return 0;
}