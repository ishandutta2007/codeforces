#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int n,taxi; 
int main()
{
	taxi=read();
	for(int i=1;i<=taxi;i++)
	{
		n=read();
		for(int i=1;i<n;i++)printf("%d ",i+1);
		printf("%d\n",1);
	}
	return 0;
}