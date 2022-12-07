#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<iostream>
#include<cstring>
using namespace std;
const int N=100005;
int n;
int a[N];
void dfs (int n)
{
    if (n==0) return;
    int now=1;
    while (now<=n) now<<=1;
    now>>=1;
    int cnt=n-now+1;
    for (int i = 1; i <= cnt; ++i)
    {
        a[now+i-1]=now-i;
        a[now-i]=now+i-1;
    }
    dfs(now-cnt-1);
}
int main()
{
	scanf("%d",&n);
	//0
	if (n%2!=0) printf("NO\n");
	else
	{
		dfs(n);
		printf("YES\n");
		for (int u=1;u<=n;u++) printf("%d ",a[u]);
		printf("\n");
	}
	//1
	if (n%2==0)// 
	{
		for (int u=1;u<=20;u++)
			if (n==(1<<u))
			{
				printf("NO\n");
				return 0;
			}
		for (int u=2;u<=n;u+=2)	{a[u]=u+1;a[u+1]=u;}
		for (int u=1;u<=20;u++)
			if ((n&(1<<u))!=0)
			{
				int t=(1<<u);
				a[n]=t;
				a[t]=n;
				a[t+1]=1;
				a[1]=t+1;
				break;
			}
		printf("YES\n");
		for (int u=1;u<=n;u++) printf("%d ",a[u]);
		return 0;
	}
	else
	{
		for (int u=2;u<=n;u+=2)	{a[u]=u+1;a[u+1]=u;}
		int now=-1,lalal;
		for (int u=1;u<=n;u+=3)// 
		{
			lalal=-1;
			bool tf=false;
			for (int i=1;i<=20;i++)
			{
				if ((u&(1<<i))!=0)
				{
					if (lalal!=-1) {tf=true;break;}
					lalal=(1<<i);
				}
			}
			if (tf==true)// 
				{now=u;break;}
		}
		if (now==-1) 	{printf("NO\n");return 0;}
		a[1]=now;a[now]=1;
		a[lalal]=lalal+1;
		a[lalal+1]=now-1;
		a[now-1]=lalal;
		printf("YES\n");
		for (int u=1;u<=n;u++) printf("%d ",a[u]);
	}
	return 0;
}