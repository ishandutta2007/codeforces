#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define LL long long
#define inf 0x3f3f3f3f
using namespace std;
int h,now,dep,t1,t2,st_t,tim,p,Test_num;
int st[132];
int a[132][5];
bool vis[132];
queue<int> q,ept;
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline void print(int x)
{
	printf("! %d\n",x),fflush(stdout);
}
inline bool query(int x)
{
	++tim,vis[x]=1,printf("? %d\n",x),fflush(stdout),read(a[x][0]);
	for(int i=1;i<=a[x][0];++i)read(a[x][i]);
	if(a[x][0]==2)print(x);
	return a[x][0]==2;
}
inline bool dfs(int x,int &t)
{
	if(query(st[++st_t]=x))return 1;
	for(int i=1;i<=a[x][0];++i)if(!vis[a[x][i]])return dfs(a[x][i],++t);
	return 0;
}
int main()
{
	for(read(Test_num);Test_num--;)
	{
		memset(vis,0,sizeof(vis)),read(h),st_t=tim=0;
		if(query(1))continue;
		if(a[1][0]>1)
		{
			if(dfs(a[1][1],t1=1))continue;
			if(dfs(a[1][2],t2=1))continue;
			if(t1==t2)now=1,dep=h-t1;
			else
			{
				if(t1<t2)now=st[(t1+t2)/2];
				else now=st[(t1-t2)/2];
				dep=h-(t1+t2)/2;
			}
		}
		else now=1,dep=h;
		while(dep>4)
		{
			for(int i=1;i<=a[now][0];++i)
				if(!vis[a[now][i]])
				{
					st_t=0;
					if(dfs(a[now][i],t1=1))goto QAQ;
					break;
				}
			now=st[(st_t-h+dep)/2],dep=(h+dep-st_t)/2;
		}
		q=ept,q.push(now);
		for(;;)
		{
			p=q.front(),q.pop();
			for(int i=1;i<=a[p][0];++i)
				if(!vis[a[p][i]])
				{
					if(tim==16)
					{
						print(a[p][i]);
						goto QAQ;
					}
					if(query(a[p][i]))goto QAQ;
					q.push(a[p][i]);
				}
		}
		QAQ:;
	}
	return 0;
}