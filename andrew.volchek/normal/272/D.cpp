#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <set>

using namespace std;
#define ull unsigned long long
pair < int, int > a[200500];




int main()
{
	int n;
	scanf("%d",&n);

	for(int i=0;i<n*2;i++)
	{
		scanf("%d",&a[i].first);
		a[i].second = i%n;

	}

	


	sort(a,a+n*2);

	long m;
	ull m2;
	scanf("%d",&m);
	m2=m;

	set < int > unq;

	ull ans = 1;

	int curr = a[0].first;
	unq.insert(a[0].second);
	int d2=0;
	int cnt =1;

	for(int i=1;i<2*n;i++)
	{
		if(a[i].first != curr)
		{
			ull mult = 1;
			int unqs=unq.size();
			for(int i=1;i<=cnt;i++)
			{
				mult *= i;
				while(d2 && !(mult&1))
				{
					mult /= 2;
					d2--;
				}
				mult %= m2;
			}
				

			
			ans = (ans % m2) * mult;
			ans %= m2;
			unq.clear();
			d2=0;
			cnt=0;
			curr = a[i].first;
		}
		if(unq.count(a[i].second))
			d2++;
		cnt++;
		unq.insert(a[i].second);
	}
	ull mult = 1;
			int unqs=unq.size();
			for(int i=1;i<=cnt;i++)
			{
				mult *= i;
				while(d2 && !(mult&1))
				{
					mult /= 2;
					d2--;
				}
				mult %= m2;
			}
			ans = (ans % m2) * mult;
	ans %= m2;

	printf("%I64d",ans);

	return 0;
}