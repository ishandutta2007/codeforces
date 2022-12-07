#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=105;
int a[N];
int n;
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
	scanf("%d",&n);
	for (int u=1;u<=n;u++) scanf("%d",&a[u]);
	int mn=a[1];
	for (int u=2;u<=n;u++) mn=min(mn,a[u]);
	int ans=0;
	for (int u=1;u<=n;u++) ans=ans+(a[u]!=mn);
	printf("%d\n",ans);
	}
	return 0;
}