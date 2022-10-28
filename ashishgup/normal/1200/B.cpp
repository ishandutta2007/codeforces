#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 105;

int n, m, k, mn = 0, mx = 0;
int a[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m >> k;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		mn = 0;
		mx = m;
		bool check = 1;
		for(int i = 1; i <= n - 1; i++)
		{
			if(a[i] > k + a[i + 1])
			{
				int maxTake = a[i] - max(0LL, a[i + 1] - k);
				mx += maxTake;
			}
			else if(a[i] + k < a[i + 1])
			{
				int minRem = a[i + 1] - (a[i] + k);
				if(minRem > mx)
				{
					check = 0;
					break;
				}
				mx -= minRem;
			}
			else
			{
				int maxTake = a[i] - max(0LL, a[i + 1] - k);
				mx += maxTake;
			}
		}
		if(check)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}