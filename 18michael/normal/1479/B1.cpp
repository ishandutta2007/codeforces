#include<cstdio>
int n,ans=0,x=0,y=0;
int a[100002],nx[100002],la[100002];
int main()
{
	scanf("%d",&n),nx[0]=n+2;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),la[i]=n+1;
	for(int i=n;i;--i)nx[i]=la[a[i]],la[a[i]]=i;
	for(int i=1;i<=n;++i)
	{
		if(a[i]==a[x]){if(a[i]!=a[y])y=i,++ans;}
		else if(a[i]==a[y])x=i,++ans;
		else if(nx[x]<nx[y])x=i,++ans;
		else y=i,++ans;
		if(a[x]==a[i])x=i;
		if(a[y]==a[i])y=i;
	}
	return 0&printf("%d",ans);
}