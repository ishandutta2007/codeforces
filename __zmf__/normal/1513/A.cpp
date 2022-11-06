//zhouakngyang txdy!
#include<bits/stdc++.h>
using namespace std;
//#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int taxi,n,k;
int main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		n=read(),k=read();
		if(k>(n-1)/2)puts("-1");
		else
		{
			for(int i=1;i<=k;i++)printf("%d %d ",i,n+1-i);
			for(int i=k+1;i<=n-k;i++)printf("%d ",i);
			puts("");
		} 
	}
	return 0;
}