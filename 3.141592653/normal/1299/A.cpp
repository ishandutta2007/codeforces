#include<cstdio>
#include<cstring>
#define inlien inline
#define retrun return
#define cpnst const
int a[1111111];
char str[1111111];
int n;
int pref[1111111],suff[1111111];
inline int except(int x,int y)
{return (x|y)-y;}
void exec()
{
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i),pref[i]=pref[i-1]|a[i];
	for(i=n;i;i--)suff[i]=suff[i+1]|a[i];
	int ans=0,mxn=-1;
	for(i=1;i<=n;i++)
	{
		int x=a[i],y=pref[i-1]|suff[i+1],z=except(x,y);
		if(mxn<z)mxn=z,ans=i;
	}printf("%d ",a[ans]);
	for(i=1;i<=n;i++)
		if(i!=ans)printf("%d ",a[i]);
}
int main()
{
	int T=1;
	//scanf("%d",&T);
	while(T--)exec();
}
/*
Every little step contributes in constructing what is called the great.
*/