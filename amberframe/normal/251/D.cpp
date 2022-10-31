#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <string.h>
#include <bitset>

typedef long long LL;
#define pb push_back
using namespace std;
const int maxn = 100005;
const int maxp = 105;
bitset<maxn> f[maxp];
int tot,n,d[maxn],ans[maxn];
LL a[maxn],sum;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("sets.in","r",stdin);
		freopen("sets.out","w",stdout);
	#endif
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%lld",&a[i]),sum^=a[i],ans[i]=1;
	for (int i=62;i>=0;i--)
	if (!((sum>>i)&1)) {
		++tot;
		for (int j=1;j<=n;j++)
			f[tot][j]=(a[j]>>i)&1;
	}
	for (int i=62;i>=0;i--)
	if (((sum>>i)&1)) {
		++tot;
		for (int j=1;j<=n;j++)
			f[tot][j]=(a[j]>>i)&1;
	}
	
	for (int i=1;i<=tot;i++) {
		f[i][0]=1;
		for (int j=1;j<i;j++)
			if (f[i][d[j]]) f[i]^=f[j];
		d[i]=1;while (d[i]<=n&&!f[i][d[i]]) ++d[i];
		if (d[i]<=n) {
			for (int j=1;j<i;j++)
				if (f[j][d[i]]) f[j]^=f[i];
		}
	}
	
	for (int i=1;i<=n;i++) ans[i]=1;
	for (int i=1;i<=tot;i++)
		if (d[i]<=n&&f[i][0]) ans[d[i]]=2;
	for (int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}