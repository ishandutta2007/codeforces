#include<cstdio>
int n,ans=0;
int a[100002],l[100002],r[100002];
inline int max(int a,int b)
{
	return a>b? a:b;
}
int main()
{
	scanf("%d",&n),l[0]=l[n+1]=r[0]=r[n+1]=0;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),l[i]=(a[i]>a[i-1]? l[i-1]+1:1);
	for(int i=n;i;--i)r[i]=(a[i]<a[i+1]? r[i+1]+1:1);
	a[0]=a[2]-2,a[n+1]=a[n-1]+2;
	for(int i=1;i<=n;++i)
	{
		if(a[i-1]+1<=a[i+1]-1)ans=max(ans,l[i-1]+r[i+1]+1);
		else ans=max(ans,max(l[i-1],r[i+1])+1);
	}
	printf("%d",ans);
	return 0;
}