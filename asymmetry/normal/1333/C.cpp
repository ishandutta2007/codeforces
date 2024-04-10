#include <bits/stdc++.h>

using namespace std;

int n, p;
int t[200001];
map <long long, int> wys;
long long s[200001];
long long odp;

int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
	{
		scanf("%d", &t[i]);
		s[i]=s[i-1]+t[i];
	}
	p=0;
	wys[0]=1;
	for(int i=0; i<n; ++i)
	{
		p=max(p, i-1);
		while(!wys[s[p+1]] && p<n)
		{
			++p;
			++wys[s[p]];
		}
		--wys[s[i]];
		odp+=p-i;
	}
	printf("%lld\n", odp);
	return 0;
}