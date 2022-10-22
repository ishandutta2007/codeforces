#include <bits/stdc++.h>

using namespace std;

const int maxDelta = 10500;
int deltas[maxDelta], suf[maxDelta];

typedef long long ll;

int main()
{
#if 1
	int n;
	scanf("%d", &n);
	
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
#else
	int n = 2000;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		a[i] = rand() % 5000 + 1;
#endif
	
	ll div = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[i] < a[j])
			{
				deltas[a[j] - a[i]]++;
				div++;
			}
			
	//printf("div %lld\n", div);
			
	long double d = (long double)div * div * div;
	ll answer = 0;
	
	for (int i = maxDelta - 2; i >= 0; i--)
		suf[i] = suf[i + 1] + deltas[i];
			
	for (int i = 1; i < maxDelta; i++)
		for (int j = 1; j < maxDelta - i; j++)
		{
			//if (pref[min(i + j, maxDelta - 1)] * (deltas[i] * deltas[j]) != 0)
			//	printf("%d %d -> %d extra (%d)\n", i, j, i + j, pref[i + j]);
			answer += (ll)suf[i + j + 1] * (deltas[i] * deltas[j]);
		}
	long double ans = answer / d;
	cout << fixed << setprecision(12) << ans << endl;
	
	return 0;
}