#include <bits/stdc++.h>

using namespace std;

int gh, n;
int stp[300001];
long long t[300001][2], odp, w;

int main()
{
	scanf("%d", &gh);
	for(int hg=0; hg<gh; ++hg)
	{
		scanf("%d", &n);
		for(int i=1; i<=n; ++i)
		{
			scanf("%lld%lld", &t[i][0], &t[i][1]);
		}
		odp=1e18;
		w=0;
		for(int i=1; i<n; ++i)
		{
			w+=max(0ll, t[i+1][0]-t[i][1]);
		}
		w+=max(0ll, t[1][0]-t[n][1]);
		t[0][1]=t[n][1];
		for(int i=1; i<=n; ++i)
		{
			odp=min(odp, t[i][0]+w-max(0ll, t[i][0]-t[i-1][1]));
		}
		printf("%lld\n", odp);
	}
	return 0;
}