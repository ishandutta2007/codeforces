//Autor: Bartomiej Czarkowski
#include <bits/stdc++.h>

using namespace std;

void solve()
{
	int n;
	scanf("%d", &n);
	vector<long long> t, r;
	for(int i=0; i<2*n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if(!y) t.push_back((long long)x*x);
		else r.push_back((long long)y*y);
	}
	sort(t.begin(), t.end());
	sort(r.begin(), r.end());
	long double odp=0.0;
	for(int i=0; i<n; ++i)
	{
		odp+=sqrtl(t[i]+r[i]);
	}
	printf("%.10Lf\n", odp);
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