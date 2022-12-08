#include<cstdio>
const int maxn=100001;
int n,k,i,a[maxn];
char s[maxn];
int main()
{
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)if(s[i]=='a')a[i]=a[i-1]+1;
	else a[i]=a[i-1];
	int l=1,r=n,mid;
	while(l<r)
	{
		mid=(l+r+1)>>1;
		bool flag=false;
		for(int i=mid;i<=n;i++)
		{
			int x=a[i]-a[i-mid],y=mid-x;
			if(x<=k||y<=k)flag=true;
			if(flag)break;
		}
		if(flag)l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
	return 0;
}