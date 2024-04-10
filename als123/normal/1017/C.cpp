#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const int N=100005;
int main()
{
	int n;
	scanf("%d",&n);
	int ans=2*n,k=1;
	for (int u=1;u<=n;u++)
	{
		int lalal=n/u;
		if (n%u!=0) lalal++;
		if (ans>lalal+u) ans=lalal+u,k=u;
	}
	int r=n;
	while (true)
	{
		int l=r-k+1;
		if (l<=0) l=1;
		for (int u=l;u<=r;u++) printf("%d ",u);
		r=l-1;if (r<=0) break;
	}
	return 0;
}