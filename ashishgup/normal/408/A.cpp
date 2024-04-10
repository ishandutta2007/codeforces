#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n;
int k[N];
int ans = 1e9;

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> k[i];
	for(int i = 1; i <= n; i++)
	{
		int sum = 15 * k[i];
		while(k[i]--)
		{
			int x;
			cin >> x;
			sum += x * 5;
		}
		int cur = sum;
		ans = min(ans, cur);
	}
	cout << ans;
	return 0;
}