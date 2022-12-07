#include <bits/stdc++.h>

using namespace std;

int gh, n, x, odp;
int t[100001];
long long s;

int main()
{
	scanf("%d", &gh);
	for(int hg=0; hg<gh; ++hg)
	{
		scanf("%d%d", &n, &x);
		for(int i=1; i<=n; ++i)
		{
			scanf("%d", &t[i]);
		}
		sort(t+1, t+1+n);
		reverse(t+1, t+1+n);
		s=0;
		odp=0;
		for(int i=1; i<=n; ++i)
		{
			s+=t[i];
			if(s>=(long long)x*i)
			{
				odp=i;
			}
		}
		printf("%d\n", odp);
	}
	return 0;
}