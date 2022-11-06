//zhouakngyang txdy!
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#define Macesuted cout<<"kawaii"<<endl
#define MatrixCascade cout<<"npsl"<<endl
#define Karry5307 cout<<"nmsl"<<endl
using namespace std;
//#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int n,cnt,flag;
char a[1009];
int main()
{
	int taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		flag=0;
		n=read();cnt=0;
		scanf("%s",a+1);
		for(int i=1;i<=n;i++)
		{
			if(a[i]=='0')cnt++;
			if(a[i]!=a[n-i+1])flag=1;
		}
		if(!flag)
		{
			if(cnt==1||cnt%2==0)puts("BOB");
			else puts("ALICE");
		}
		else
		{
			if(cnt==2&&n%2==1&&a[n/2+1]=='0')puts("DRAW");
			else puts("ALICE");
		}
	}
	return 0;
}