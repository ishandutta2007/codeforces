#include<bits/stdc++.h>
using namespace std;
int n,t;
int a[102];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(n),a[n]=0;
	for(int i=2;i<=n;++i)
	{
		printf("? ");
		for(int j=1;j<n;++j)printf("1 ");
		printf("%d\n",i),fflush(stdout),read(t);
		if(!t){a[n]=n+2-i;break;}
	}
	if(!a[n])a[n]=1;
	for(int i=2;i<=a[n];++i)
	{
		printf("? ");
		for(int j=1;j<n;++j)printf("%d ",i);
		printf("1\n"),fflush(stdout),read(t),a[t]=a[n]-i+1;
	}
	for(int i=1;i<=n-a[n];++i)
	{
		printf("? ");
		for(int j=1;j<n;++j)printf("1 ");
		printf("%d\n",i+1),fflush(stdout),read(t),a[t]=a[n]+i;
	}
	printf("! ");
	for(int i=1;i<=n;++i)printf("%d%c",a[i],i==n? '\n':' ');
	fflush(stdout);
	return 0;
}