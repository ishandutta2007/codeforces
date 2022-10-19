#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int n,l=0,r=0,ans=0,ch_t=0;
bool ok;
char ch[1000002];
int main()
{
	scanf("%d",&n),ch[1]=getchar();
	while(ch[1]!='(' && ch[1]!=')')ch[1]=getchar();
	for(int i=2;i<=n;i++)ch[i]=getchar();
	if(n&1)
	{
		printf("-1");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(ch[i]=='(')++l,ok=1;
		else ++r,ok=0;
		if(l==r)
		{
			if(ok)ans+=(l<<1);
			l=r=0;
			continue;
		}
		ch[++ch_t]=ch[i];
	}
	if(l!=r)
	{
		printf("-1");
		return 0;
	}
	printf("%d",ans);
	return 0;
}