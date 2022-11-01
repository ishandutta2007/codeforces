#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int main()
{
	int T=read();
	while (T--)
	{
		int n=read(),ans=0;
		if (n%2==1)
		{
			if (n<9)
			{
				puts("-1");
				continue;
			}
			n-=9;ans++;
		}
		if (n==2)
		{
			puts("-1");
			continue;
		}
		if (n/2%2==0) ans+=n/4;
		else ans+=(n-6)/4+1;
		printf("%d\n",ans);
	}
	return 0;
}