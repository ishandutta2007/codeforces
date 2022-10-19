#include<bits/stdc++.h>
using namespace std;
int n,sum=0,t=0;
int X[4102],p[4102],q[4102],top[4102]={},toq[4102]={};
int main()
{
	srand(time(NULL)),scanf("%d",&n),n=(1<<n);
	for(int i=1;i<=n;++i)scanf("%d",&X[i]),sum^=X[i],p[i]=q[i]=-1;
	if(sum)return 0&puts("Fou");
	puts("Shi");
	for(int x,y;t<n;)
	{
		do x=rand()%n+1;while(~p[x]);
		for(int i=0;i<n;++i)
			if(!top[i] && !toq[i^X[x]])
			{
				top[p[x]=i]=toq[q[x]=(i^X[x])]=x,++t;
				break;
			}
		if(~p[x])continue;
		do y=rand()%n;while(top[y]);
		top[p[toq[y^X[x]]]]=0,p[toq[y^X[x]]]=q[toq[y^X[x]]]=-1,top[p[x]=y]=toq[q[x]=(y^X[x])]=x;
	}
	for(int i=1;i<=n;++i)printf("%d%c",p[i],i==n? '\n':' ');
	for(int i=1;i<=n;++i)printf("%d%c",q[i],i==n? '\n':' ');
	return 0;
}