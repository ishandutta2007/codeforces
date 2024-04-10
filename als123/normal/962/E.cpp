#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const LL N=200005;
LL n;
struct qq
{
	LL x,o;//0 
}s[N];
int main()
{
	scanf("%I64d",&n);
	for (LL u=1;u<=n;u++)
	{
		scanf("%I64d",&s[u].x);
		char ch=getchar();
		while (ch!='R'&&ch!='B'&&ch!='P') ch=getchar();
		if (ch=='R') s[u].o=1;
		if (ch=='B') s[u].o=2;
		if (ch=='P') s[u].o=0;
	}
/*	for (LL u=1;u<=n;u++)
		printf("%I64d %I64d\n",s[u].x,s[u].o);*/
	LL ans=0;
	LL last=-1;
	for (LL u=1;u<=n;u++)
		if (s[u].o==0||s[u].o==1)
		{
			if (last!=-1) ans=ans+s[u].x-s[last].x;
			last=u;
		}	
	//	printf("%I64d\n",ans);
	last=-1;
	for (LL u=1;u<=n;u++)
		if (s[u].o==0||s[u].o==2)
		{
			if (last!=-1) ans=ans+s[u].x-s[last].x;
			last=u;
		}

	last=-1;
	for (LL u=1;u<=n;u++)
		if (s[u].o==0)
		{
			if (last!=-1)	
			{
				LL lalal=(s[u].x-s[last].x)*2;//
				LL lalal1=(s[u].x-s[last].x)*3;
				LL last1=-1,mx=0;
				for (LL i=last;i<=u;i++)
				{
					if (s[i].o==1||s[i].o==0)
					{
						if (last1!=-1) mx=max(mx,s[i].x-s[last1].x);
						last1=i;
					}
				}
				lalal1=lalal1-mx;
				last1=-1,mx=0;
				for (LL i=last;i<=u;i++)
				{
					if (s[i].o==2||s[i].o==0)
					{
						if (last1!=-1) mx=max(mx,s[i].x-s[last1].x);
						last1=i;
					}
				}
				lalal1=lalal1-mx;
				if (lalal1<lalal)
					ans=ans-lalal+lalal1;
			}
			last=u;
		}
	printf("%I64d\n",ans);
	return 0;
}