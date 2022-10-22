#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	ll n, k, x;
	cin >> n >> k >> x;
	
	vector<ll> a(n), prefixOr(n), suffixOr(n);
	
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	for (int i = 0; i < n; i++)
		prefixOr[i] = (i ? prefixOr[i - 1] : 0) | a[i];
	
	for (int i = n - 1; i >= 0; i--)
		suffixOr[i] = (i + 1 != n ? suffixOr[i + 1] : 0) | a[i];
	
	ll mult = 1;
	for (int i = 0; i < k; i++)
		mult *= x;
	
	ll answer = 0;
	for (int i = 0; i < n; i++)
	{
		ll can = (a[i] * mult) | (i ? prefixOr[i - 1] : 0) | (i + 1 != n ? suffixOr[i + 1] : 0);
		if (can > answer)
			answer = can;
	}
	
	cout << answer << endl;
	
	return 0;
}