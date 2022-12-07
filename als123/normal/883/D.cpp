#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1000005;
int n;
char ss[N];
int a[N];
int p[N],tot=0;
int f[N];//q 
bool ok (int l,int r)// 
{
	if (l>r) return true;
	return a[r]-a[l-1]<=0;
}
bool check (int x)
{
	memset(f,0,sizeof(f));
	for (int u=1;u<=tot;u++)// 
	{
		//
		if (ok(f[u-1]+1,p[u]-x-1)) f[u]=max(f[u],p[u]);
		// 
		if (ok(f[u-1]+1,p[u]-1)) f[u]=max(f[u],p[u]+x);
		//
		if (u>1)
		{
			if (ok(f[u-2]+1,p[u]-x-1)) f[u]=max(f[u],p[u-1]+x);
		}
	//	printf("%d ",f[u]);
	}
	return ok(f[tot]+1,n);
}
int main()
{
	scanf("%d",&n);
	scanf("%s",ss+1);
	a[0]=0;
	for (int u=1;u<=n;u++) a[u]=a[u-1]+(ss[u]=='*');
//	printf("YES");
	for (int u=1;u<=n;u++)
		if (ss[u]=='P')
			p[++tot]=u;
	if (tot==1)
	{
		int p1=a[p[tot]],p2=a[n]-a[p[tot]];
		int c1=p[1]-1,c2=n-p[1];
		for (int u=1;u<p[1];u++)
			if (ss[u]=='.') c1--;
			else break;
		for (int u=n;u>p[1];u--)
			if (ss[u]=='.')  c2--;
			else break;
		if (p1>p2||(p1==p2&&c1<c2))
			printf("%d %d\n",p1,c1);
		else
			printf("%d %d\n",p2,c2);
	}
	else
	{
		printf("%d ",a[n]);
		int l=1,r=n;
		int ans=0;
		while (l<=r)
		{
			int mid=(l+r)>>1;
			if (check(mid)) {ans=mid;r=mid-1;}
			else l=mid+1;
		}
		printf("%d\n",ans);
	}
	return 0;
}