#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n; long long a[N];
pair<long long,long long> pref[N], suf[N];

int main()
{	
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i)
		scanf("%lld", &a[i]);
	for (int i = 1; i <= n; ++ i)
	{
		pref[i].first = a[i];
		pref[i].second = pref[i-1].second;
		if (pref[i].first <= pref[i-1].first)
		{
			pref[i].second += pref[i-1].first - pref[i].first + 1;
			pref[i].first += pref[i-1].first - pref[i].first + 1;
		}
	}
	for (int i = n; i >= 1; -- i)
	{
		suf[i].first = a[i];
		suf[i].second = suf[i+1].second;
		if (suf[i].first <= suf[i+1].first)
		{
			suf[i].second += suf[i+1].first - suf[i].first + 1;
			suf[i].first += suf[i+1].first - suf[i].first + 1;
		}
	}
	long long wyn = 1e18;
	for (int i = 0; i <= n; ++ i)
	{
		if (pref[i].first != suf[i+1].first)
			wyn = min(wyn, pref[i].second + suf[i+1].second);
		else
			wyn = min(wyn, pref[i].second + suf[i+1].second + 1);
	}
	printf("%lld\n", wyn);
	return 0;
}