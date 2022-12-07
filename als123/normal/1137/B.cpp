#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=500005;
char a[N],b[N];
int g=0,h=0;
int n,m;
int f[N];
int t1=0,t0=0;
int main()
{
	scanf("%s%s",a+1,b+1);
	n=strlen(a+1);m=strlen(b+1);
	for (int u=1;u<=n;u++)
	{
		if (a[u]=='0') h++;
		else g++;
	}
	int j=0;f[1]=0;
	for (int i=2;i<=m;i++)
	{
		while (j!=0&&b[i]!=b[j+1]) j=f[j];
		if (b[i]==b[j+1]) j++;
		f[i]=j;
	}
	for(int i=1;i<=m;i++) if(b[i]=='1') t1++;else t0++;
	bool tf=false;
	while(g>=t1&&h>=t0)
	{
		g-=t1;h-=t0;
		if(!tf)
		{
			printf("%s",b+1);
			tf=true;t1=t0=0;
			for(int i=f[m]+1;i<=m;i++) 
			if(b[i]=='1') t1++;
			else t0++;
		}
		else for(int i=f[m]+1;i<=m;i++) printf("%c",b[i]);
	}
	for(int i=1;i<=g;i++) printf("1");
	for(int i=1;i<=h;i++) printf("0");
	return 0;
}