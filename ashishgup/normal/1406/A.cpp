#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 105;

int n;
int a[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		vector<int> f(105, 0);
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			f[a[i]]++;
		}
		int ans = 0;
		for(int i = 0; i <= 100; i++)
		{
			if(f[i] > 0)
			{
				ans++;
				f[i]--;
			}
			else
				break;
		}
		for(int i = 0; i <= 100; i++)
		{
			if(f[i] > 0)
			{
				ans++;
				f[i]--;
			}
			else
				break;
		}
		cout << ans << endl;
	}
	return 0;
}