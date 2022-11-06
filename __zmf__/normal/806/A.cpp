//zhouakngyang txdy!
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int taxi,a,b,p,q;
signed main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		a=read(),b=read();p=read(),q=read();
		if(p==0)
		{
			if(a==0)puts("0");
			else puts("-1");
			continue;
		}
		else if(p==q)
		{
			if(a==b)puts("0");
			else puts("-1");
			continue;
		}
		int qwq=(a+p-1)/p*p;
		//cout<<qwq<<endl;
		int x1=qwq-a,x2=qwq/p*q-b;
		if(x1<=x2)
		{
			printf("%lld\n",x2);continue;
		}
		else
		{
			int delta=x1-x2,qaq=(delta-1)/(q-p)+1;
			printf("%lld\n",x2+qaq*q);continue;
		}
	}
	return 0;
}