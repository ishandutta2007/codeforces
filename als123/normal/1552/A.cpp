#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=50;
char a[N],b[N];
int n;
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		scanf("%s",a+1);
		for (int u=1;u<=n;u++)b[u]=a[u];
		sort(b+1,b+1+n);
		int ans=0;
		for (int u=1;u<=n;u++) if (a[u]!=b[u]) ans++;
		printf("%d\n",ans);
	}
	return 0;
}