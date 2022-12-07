#include <bits/stdc++.h>

using namespace std;

int l;
int sum[100001];
char s[100001];

void solve()
{
	int n, p, k, x, y;
	scanf("%d%d%d", &n, &p, &k);
	scanf("%s", s+1);
	scanf("%d%d", &x, &y);
	int odp=1e9;
	for(int i=n; i; --i)
	{
		sum[i]=0;
		if(i+k<=n)
		{
			sum[i]+=sum[i+k];
		}
		sum[i]+=(s[i]=='0')*x;
	}
	for(int i=p; i<=n; ++i)
	{
		odp=min(odp, y*(i-p)+sum[i]);
	}
	printf("%d\n", odp);
}

int main()
{
	int q;
	scanf("%d", &q);
	while(q--)
	{
		solve();
	}
	return 0;
}