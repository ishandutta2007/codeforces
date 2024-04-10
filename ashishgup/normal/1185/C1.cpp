#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, m;
int a[N];
int f[N];

int32_t main()
{
	IOS;
	cin >> n >> m;
	int total = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		int rem = total;
		rem -= (m - a[i]);
		int ans = 0;
		if(rem <= 0)
			cout << 0 << " ";
		else
		{
			for(int j = 100; j >= 1; j--)
			{
				if(f[j] * j <= rem)
				{
					rem -= f[j] * j;
					ans += f[j];
				}
				else
				{
					int cur = (rem + j - 1) / j;
					ans += cur;
					break;
				}
			}
			cout << ans << " ";
		}	
		f[a[i]]++;
		total += a[i];
	}
	return 0;
}