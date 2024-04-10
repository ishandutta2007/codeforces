#include <bits/stdc++.h>

using namespace std;

int gh;
long long m, g, l, r;

int main()
{
	scanf("%d", &gh);
	for(int hg=0; hg<gh; ++hg)
	{
		scanf("%lld%lld%lld", &l, &r, &m);
		for(long long i=l; i<=r; ++i)
		{
			if(m>=i && r-l>=m%i)
			{
				printf("%lld %lld %lld\n", i, l+m%i, l);
				break;
			}
			if(abs(m%i-i)<=r-l)
			{
				printf("%lld %lld %lld\n", i, l, l+abs(m%i-i));
				break;
			}
		}
	}
	return 0;
}