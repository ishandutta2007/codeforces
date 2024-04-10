#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n;
int a[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		int sum = 0;
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			sum += a[i];
		}
		int mx = -1e18, cur = 0;
		for(int i = 2; i <= n; i++)
		{
			cur += a[i];
			mx = max(mx, cur);
			if(cur < 0)
				cur = 0;
		}	
		cur = 0;
		for(int i = 1; i < n; i++)
		{
			cur += a[i];
			mx = max(mx, cur);
			if(cur < 0)
				cur = 0;
		}	
		if(mx >= sum)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return 0;
}