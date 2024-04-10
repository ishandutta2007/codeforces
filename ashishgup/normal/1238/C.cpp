#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, h;
int a[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> h >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		a[n + 1] = 0;
		n++;
		int ans = 0;
		for(int i = 1; i <= n;)
		{
			if(i == n)
				break;
			if(a[i] == 1)
				break;
			if(a[i + 1] == a[i] - 1)
			{
				if(i + 2 <= n && a[i + 2] == a[i] - 2)
				{
					i = i + 2;
					continue;
				}
				else if(i + 2 > n)
				{
					ans++;
					i = n + 1;
					break;
				}
				else
				{
					ans++;
					a[i + 1] = a[i] - 2;
					i++; 
				}
			}
			else
			{
				a[i] = a[i + 1] + 1;
				continue;
			}
		}
		cout << ans << endl;
	}
	return 0;
}