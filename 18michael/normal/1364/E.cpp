#include<bits/stdc++.h>
using namespace std;
int n,res,las=1;
int id[2052],p[2052];
inline int query(int a)
{
	int t=~0,ed=min(n,14);
	for(int i=1,x;i<=ed;++i)
	{
		if(id[i]==a)ed=min(ed+1,n);
		else printf("? %d %d\n",a,id[i]),fflush(stdout),scanf("%d",&x),t&=x;
	}
	return t;
}
int main()
{
	srand(time(NULL)),scanf("%d",&n);
	for(int i=1;i<=n;++i)id[i]=i;
	for(int i=1;i<=n;++i)swap(id[i],id[rand()%n+1]);
	res=query(1);
	for(int i=2,x;i<=n;++i)
	{
		printf("? %d %d\n",las,i),fflush(stdout),scanf("%d",&x);
		if((x&res)==x)res=query(las=i);
	}
	for(int i=1;i<=n;++i)
	{
		if(i==las)continue;
		printf("? %d %d\n",las,i),fflush(stdout),scanf("%d",&p[i]);
	}
	printf("! ");
	for(int i=1;i<=n;++i)printf("%d%c",p[i],i==n? '\n':' ');
	return 0&fflush(stdout);
}