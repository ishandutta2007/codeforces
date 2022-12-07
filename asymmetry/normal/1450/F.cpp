#include <bits/stdc++.h>

using namespace std;

int t[100001];
int zl[100001];
int lz[100001];

void solve()
{
	int n, ans=0;
	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
	{
		zl[i]=0;
		lz[i]=0;
	}
	for(int i=1; i<=n; ++i)
	{
		scanf("%d", &t[i]);
		++zl[t[i]];
	}
	for(int i=1; i<=n; ++i)
	{
		if(zl[i]>(n+1)/2)
		{
			printf("-1\n");
			return;
		}
	}
	for(int i=2; i<=n; ++i)
	{
		if(t[i]==t[i-1])
		{
			++ans;
			++lz[t[i]];
			++lz[t[i-1]];
		}
	}
	++lz[t[1]];
	++lz[t[n]];
	for(int i=1; i<=n; ++i)
	{
		if(lz[i]-2>(ans+1)*2-lz[i])
		{
			ans+=(lz[i]-2-(ans+1)*2+lz[i]+1)/2;
			break;
		}
	}
	printf("%d\n", ans);
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