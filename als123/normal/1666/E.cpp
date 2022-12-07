#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=100005;
const int inf=2e9;
int d,n;
int a[N];
int L[N],R[N];
bool checkl (int x)
{
	int now=0;
	for (int u=1;u<=n;u++)
	{
		now=now+x;
		if (now>a[u+1])  return false;
		if (now<a[u]) now=a[u];
	}
	return true;
}
bool check  (int l,int r)
{
	L[0]=0;R[0]=0;
	for (int u=1;u<=n;u++)
	{
		if (R[u-1]+r<a[u]) return false;
		L[u]=max(L[u-1]+l,a[u]);
		R[u]=min(R[u-1]+r,min(a[u+1],a[u+2]-l));
	}
	if (R[n]<d) return false;
	return true;
}
int ansl[N],ansr[N];
int main()
{
	scanf("%d%d",&d,&n);
	for (int u=1;u<=n;u++)	scanf("%d",&a[u]);
	a[n+1]=d;
	a[n+2]=inf;
	int l=1,r=d,p=-1;
	while (l<=r)
	{
		int mid=(l+r)>>1;
		if (checkl(mid))	{p=mid;l=mid+1;}
		else r=mid-1;
	}
	l=p;r=d;int rr=-1;
	while (l<=r)
	{
		int mid=(l+r)>>1;
		if (check(p,mid)) {rr=mid;r=mid-1;}
		else l=mid+1;
	}
	//printf("%d %d %d\n",p,rr,rr-p);
	check(p,rr);
	int now=R[n];
	for (int u=n;u>=1;u--) 
	{
		
		int t=min(R[u-1],now-p);
		ansl[u]=t;ansr[u]=now;
		now=t;
		//printf("%d %d\n",R[u-1],R[u]);
	}
	for (int u=1;u<=n;u++) printf("%d %d\n",ansl[u],ansr[u]);
	return 0;
}