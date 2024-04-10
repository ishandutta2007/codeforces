#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 20;

int a[maxn] , s[maxn];

int solve()
{
	int k;
	cin >> k;

	for(int i = 0; i < 7; i++)
		cin >> a[i] , s[i + 1] = s[i] + a[i];

	int res = 1e9;
	for(int l = 0; l < 7; l++)
		for(int r = l + 1; r <= 7; r++)
			if(s[r] - s[l] == k)
				res = min(res , r - l);

	for(int l = 0; l < 7; l++)
		for(int r = 0; r < 7; r++)
		{
			int tmp = k - (s[7] - s[l] + s[r]);

			if(tmp % s[7] == 0)
				res = min(res , r + (7 - l) + tmp / s[7] * 7);
		}

	cout << res << endl;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		solve();
	}
}