#include <bits/stdc++.h>
#define MAXN 5005

using namespace std;

int main ()
{
	int N;
	scanf("%d",&N);
	static int a[MAXN];
	int i;
	for (i = 0; i < N; i++)
	{
		scanf("%d",&a[i]);
		a[i]--;
	}
	static int cnt[MAXN];
	static int res[MAXN];
	memset(res,0,sizeof(res));

	int j;
	for (i = 0; i < N; i++)
	{
		memset(cnt,0,sizeof(cnt));
		int best = -1;
		int bestind = -1;
		for (j = i; j < N; j++)
		{
			cnt[a[j]]++;
			if (cnt[a[j]] > best)
			{
				best = cnt[a[j]];
				bestind = a[j];
			}
			else if ((cnt[a[j]] == best) && (a[j] < bestind))
			{
				best = cnt[a[j]];
				bestind = a[j];
			}
			res[bestind]++;
		}
	}

	for (i = 0; i < N; i++)
	{
		if (i) printf(" ");
		printf("%d",res[i]);
	}
	printf("\n");
	return 0;	
}