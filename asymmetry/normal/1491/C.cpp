//Autor: Bartomiej Czarkowski
#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n;
	scanf("%d", &n);
	vector <int> t(n+1), zl(n+1, 0);
	for(int i=0; i<n; ++i) scanf("%d", &t[i]);
	long long odp=0;
	for(int i=0; i<n; ++i)
	{
		//~ printf("%d: %d %d\n", i, t[i], zl[i]);
		if(t[i]-1>zl[i])
		{
			//~ printf("odp+=%d\n", t[i]-zl[i]-1);
			odp+=t[i]-zl[i]-1;
			zl[i]+=t[i]-1-zl[i];
			for(int j=i+2; j<min(n, i+t[i]+1); ++j) ++zl[j];
		}
		else
		{
			for(int j=i+2; j<min(n, i+t[i]+1); ++j) ++zl[j];
			zl[i+1]+=zl[i]-t[i]+1;
		}
	}
	printf("%lld\n", odp);
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