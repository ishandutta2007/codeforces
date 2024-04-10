#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;

int n;
int a[N];

int get(int x)
{
	int ans = 0;
	int delta = 0;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] != x)
			delta += (x - a[i]);
		ans += abs(delta);
		x ^= 1;
	}
	return ans;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		vector<int> f(2, 0);
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			a[i] = a[i] % 2;
			f[a[i]]++;
		}
		if(n % 2 == 0)
		{
			if(f[0] == f[1])
			{
				int ans = min(get(0), get(1));
				cout << ans << endl;
			}
			else
				cout << -1 << endl;
		}
		else
		{
			if(f[0] == f[1] + 1)
				cout << get(0) << endl;
			else if(f[1] == f[0] + 1)
				cout << get(1) << endl;
			else
				cout << -1 << endl;
		}
	}
	return 0;
}