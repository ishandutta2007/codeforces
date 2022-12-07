//Autor: Bartomiej Czarkowski
#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n;
	long long u, v;
	scanf("%d%lld%lld", &n, &u, &v);
	vector <int> t(n);
	for(int i=0; i<n; ++i) scanf("%d", &t[i]);
	bool ok=true;
	for(int i=1; i<n; ++i) if(t[i-1]!=t[i]) ok=false;
	if(ok)
	{
		printf("%lld\n", min(v+v, u+v));
		return;
	}
	//~ int a=1e9;
	for(int i=1; i<n; ++i)
	{
		if(abs(t[i]-t[i-1])>=2)
		{
			printf("0\n");
			return;
		}
	}
	printf("%lld\n", min(v, u));
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