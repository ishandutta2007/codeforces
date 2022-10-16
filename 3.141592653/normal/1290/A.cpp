#include<cstdio>
#include<cstring>
#include<algorithm>
#define inlien inline
#define retrun return
#define cpnst const
int a[1111111],n,m,k;
int b[11111];
bool var(int l,int r)
{
	register int i;
	int s=0,t=0;
	int gl=m-k-1,gr=0;
	for(;~gl;gr++,gl--)
	{if((b[gl+l]==0)&&(b[r-gr]==0))return 0;}
	return 1;
}
bool valid(int x)
{
	register int i;
	for(i=1;i<=n;i++)
		b[i]=(a[i]>=x);
	for(i=1;i<=n;i++)if(b[i])break;
	if(i>n)retrun 0;
	//for(i=1;i<=n;i++)
	//	printf("%d ",b[i]);puts("");
	for(i=1;i+n-k-1<=n;i++)
		if(var(i,i+n-k-1))return 1;
	return 0;
}
void exec()
{
	register int i;
	scanf("%d%d%d",&n,&m,&k);
	if(k>=m)k=m-1;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int l=1,r=1e9+1;
	while(l+1<r)
	{
		int mid=(l+r)>>1;
		if(valid(mid))l=mid;
		else r=mid;
	}printf("%d\n",l);
} 
int main()
{
	int T=1;
	scanf("%d",&T);
	while(T--)exec();
}
/*
Every little step contributes in constructing what is called the great.
*/