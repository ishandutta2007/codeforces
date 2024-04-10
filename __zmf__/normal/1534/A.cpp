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
int taxi,n,m,r,b,flag;
char a[59][59];
int main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		r=-1,b=-1;flag=0;
		n=read(),m=read();
		for(int i=1;i<=n;i++)scanf("%s",a[i]+1);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(a[i][j]=='R')
				{
					if(r==-1)r=(i+j)%2,b=(i+j+1)%2;
					else if(r!=(i+j)%2)flag=1;
				}
				else if(a[i][j]=='W')
				{
					if(b==-1)b=(i+j)%2,r=(i+j+1)%2;
					else if(b!=(i+j)%2)flag=1;
				}
		if(flag)
		{
			puts("NO");continue;
		}
		if(r==-1&&b==-1)r=0,b=1;
		puts("YES");
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				if(r==(i+j)%2)putchar('R');
				else putchar('W');
			puts("");
		}
	}
	return 0;
}