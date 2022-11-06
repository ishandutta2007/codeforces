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
int n,a,b,c,ans;
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		a=read(),b=read(),c=read();
		ans=min((a+b+c)/3,min(a,b));
		printf("%d\n",ans);
	}
	return 0;
}