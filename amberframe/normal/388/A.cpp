#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>

using namespace std;
const int maxn = 105;
const int N = 100;
int cnt,a[maxn],ans,n;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("box.in","r",stdin);
		freopen("box.out","w",stdout);
	#endif
	scanf("%d",&n);
	for (int x,i=1;i<=n;i++)
		scanf("%d",&x),a[x]++,++cnt;
	while (cnt)
	{
		++ans;int o=0;
		for (int i=0;i<=N;i++)
		{
			o=max(o,i);while (o<=N&&!a[o]) ++o;
			if (o>N) break;cnt--;a[o]--;
		}
	}
	printf("%d",ans);
	return 0;
}