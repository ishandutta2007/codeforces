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
int n;
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			if((i+j)%2==0)putchar('W');
			else putchar('B');
		puts("");
	}
	return 0;
}