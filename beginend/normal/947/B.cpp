#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

typedef long long LL;

const int N=100005;

int n;
LL v[N],t[N];
priority_queue<LL> que;

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int main()
{
	n=read();
	for (int i=1;i<=n;i++) v[i]=read();
	for (int i=1;i<=n;i++) t[i]=read();
	LL tag=0;
	for (int i=1;i<=n;i++)
	{
		LL ans=0;
		que.push(-v[i]-tag);
		while (!que.empty()&&-que.top()<=tag+t[i]) ans+=-que.top()-tag,que.pop();
		ans+=t[i]*que.size();
		tag+=t[i];
		printf("%I64d ",ans);
	}
	return 0;
}