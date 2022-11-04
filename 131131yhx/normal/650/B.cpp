#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

ll n, a, b, T, Max = 1;

char ch1[500010], ch2[500010];

ll Time1[500010], Time2[500010];

int main()
{
	scanf("%lld%lld%lld%lld", &n, &a, &b, &T);
	scanf("%s", ch1);
	for(ll i = 1; i < n; i++) ch2[n - i] = ch1[i];
	T -= (ch1[0] == 'w') * b + 1;
	if(T < 0)
	{
		puts("0");
		return 0;
	}
	for(ll i = 1; i < n; i++) Time1[i] = Time1[i - 1] + a + (ch1[i] == 'w') * b + 1;
	for(ll i = 1; i < n; i++) Time2[i] = Time2[i - 1] + a + (ch2[i] == 'w') * b + 1;
	for(ll i = 1; i < n; i++)
		if(Time1[i] < T)
		{
			Max = max(Max, i);
			break;
		}
	for(ll i = 1; i < n; i++)
		if(Time2[i] < T)
		{
			Max = max(Max, i);
			break;
		}
	if(Time1[n - 1] <= T || Time2[n - 1] <= T)
	{
		printf("%lld\n", n);
		return 0;
	}
	ll p = n - 1;
	for(ll i = 1; i < n; i++)
	{
		ll tmp = T - Time1[i];
		if(tmp < 0) break;
		while(p != 0 && Time2[p] + i * a > tmp) p--;
		Max = max(Max, p + i + 1);
	}
	p = n - 1;
	for(ll i = 1; i < n; i++)
	{
		ll tmp = T - Time2[i];
		if(tmp < 0) break;
		while(p != 0 && Time1[p] + i * a > tmp) p--;
		Max = max(Max, p + i + 1);
	}
	printf("%lld\n", min(Max, n));
	return 0;
}