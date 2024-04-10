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
int m,n,k;
double ans=1;
int main()
{
	n=read(),m=read(),k=read();
	if(k>=m)
	{
		puts("1.0000");return 0;
	}
	else if(m>n+k)
	{
		puts("0.0000");return 0;
	}
	for(int i=1;i<=k+1;i++)ans=ans*1.0/(n+i)*1.0*(m-k-1+i)*1.0;
	printf("%.12lf\n",1-ans);
	return 0;
}