#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1005;

int n, x;
int a[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> x;
		int sum = 0, flag = 0, have = 0;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			sum += a[i];
			if(a[i] == x)
			{
				have = 1;
				continue;
			}
			flag = 1;
		}
		int ans = (sum != n * x && have == 0) + flag;
		cout << ans << endl;
	}
	return 0;
}