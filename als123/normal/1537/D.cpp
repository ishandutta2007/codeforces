#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const LL N=200005;
LL T;
LL n,m;
LL a[N],b[N];
vector<int> vec[N];
bool tf;
LL dep[N];
void dfs (LL x,LL fa)
{
	dep[x]=dep[fa]+1;
	LL siz=vec[x].size();
	for (LL u=0;u<siz;u++)
	{
		LL y=vec[x][u];
		if (y==fa) continue;
		if (dep[y]==-1)
		{
			dfs(y,x);
			a[x]=a[x]+(b[y]-a[y]);
		}
		else
		{
			LL t=dep[x]-dep[y];
			if (t%2==0) tf=true;
		}
	}
}
int main()
{
	scanf("%lld",&T);
	while (T--)
	{
		int n;
		scanf("%d",&n);
		int k=0;
		while (n%2==0) {k++;n/=2;}
		if (n==1)
		{
			if (k%2==1||k==0) printf("Bob\n");
			else printf("Alice\n"); 
		}
		else	if (k!=0) printf("Alice\n");
		else printf("Bob\n");
	}
	return 0;
}