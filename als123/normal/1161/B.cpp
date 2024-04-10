#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
typedef unsigned long long ULL;
typedef long long LL;
map<pair<int,int>,int> mp;
const int N=200005;
const int base=2333;
vector<int> vec[N];
int n,m; 
bool ok[N];
ULL P[N];
int a[N],b[N];
int f[N];
int vis[N],tim=0;
int L[N],R[N];
bool check (int x)
{
	for (int u=1;u<=m;u++)
	{
		int ll=L[u]+x,rr=R[u]+x;
		if (ll>n) ll-=n;
		if (rr>n) rr-=n;
		if (mp[{ll,rr}]==0) return false;
	}
	return true;
}
int main()
{
	scanf("%d%d",&n,&m);
	P[0]=1;for (int u=1;u<=2*n;u++) P[u]=P[u-1]*base;
	for (int u=1;u<=m;u++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		mp[{l,r}]=1;mp[{r,l}]=1;
		L[u]=l;R[u]=r;
	}
	for (int u=1;u<=n;u++) sort(vec[u].begin(),vec[u].end());
	/*memset(ok,true,sizeof(ok));
	for (int u=1;u<=n;u++)
	{
		int siz=vec[u].size();	
		if (siz==0)	continue;
		if (siz==1)	{printf("No\n");return 0;}
		sort(vec.begin(),vec.end());
		int cnt=0;
		for (int i=0;i<siz;i++) a[++cnt]=vec[i];
		for (int i=0;i<siz;i++) a[++cnt]=vec[i]+n;
		for (int i=1;i<=cnt;i++) b[i]=a[i+1]-a[i];
		for (int j=1;j<)
	}	
	printf("Yes\n");*/
	for (int u=1;u<n;u++)	if (n%u==0)
	{
		if (check(u))
		{
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}