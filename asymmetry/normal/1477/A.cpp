//Autor: Bartomiej Czarkowski
#include <bits/stdc++.h>

using namespace std;

#define N 201 * 1000

long long t[N];

void solve()
{
	int n;
	long long k;
	scanf("%d%lld", &n, &k);
	for(int i=1; i<=n; ++i)
	{
		scanf("%lld", &t[i]);
	}
	sort(t+1, t+1+n);
	long long g=t[2]-t[1];
	for(int i=3; i<=n; ++i)
	{
		g=__gcd(g, t[i]-t[i-1]);
	}
	if(abs(k-t[1])%g) printf("NO\n");
	else printf("YES\n");
}

int main()
{
	//~ ios_base::sync_with_stdio(false);
	//~ cin.tie(NULL);
	int q=1;
	scanf("%d", &q);
	while(q--)
	{
		solve();
	}
	return 0;
}