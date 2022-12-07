//Autor: Bartomiej Czarkowski
#include <bits/stdc++.h>

using namespace std;

const int N = 100100;
int n;
int t[N];

void solve()
{
	scanf("%d", &n);
	bool ok=true;
	long long nww=1;
	for(int i=1; i<=n; ++i)
	{
		scanf("%d", &t[i]);
		if(nww>1e9) continue;
		nww=nww*(i+1)/__gcd(nww, (long long)i+1);
		if(t[i]%nww==0)
		{
			ok=false;
		}
	}
	if(ok) printf("YES\n");
	else printf("NO\n");
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