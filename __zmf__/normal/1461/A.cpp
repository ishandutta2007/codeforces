#include<bits/stdc++.h>
using namespace std;
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
		for(int i=1;i<=n/3;i++)printf("abc");
		for(int i=1;i<=n%3;i++)printf("%c",(char)'a'+i-1);
		puts("");
	}
	return 0;
}