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
int l,r,a[400009],x,taxi,pos[200009],ans,qwq;
char pp;
signed main()
{
	taxi=read();
	l=2e5+1,r=2e5;
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		cin>>pp;x=read();
		if(pp=='L')
		{
			l--,a[l]=x;pos[x]=l;
		}
		if(pp=='R')
		{
			r++,a[r]=x;pos[x]=r;
		}
		if(pp=='?')
		{
			qwq=pos[x];
			ans=min(qwq-l,r-qwq);
			printf("%d\n",ans);
		}
	}
	return 0;
}