#include<cstdio>
int n,mx=0;
int a[500002],l[500002]={},r[500002]={},f[500002],cnt[500002];
inline int max(int x,int y)
{
	return x>y? x:y;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		if(!l[a[i]])l[a[i]]=i;
	}
	for(int i=n;i;--i)
	{
		if(!r[a[i]])r[a[i]]=i;
		f[i]=max(f[i+1],mx=max(mx,++cnt[a[i]]));
		if(l[a[i]]==i)f[i]=max(f[i],cnt[a[i]]+f[r[a[i]]+1]);
	}
	return 0&printf("%d",n-f[1]);
}