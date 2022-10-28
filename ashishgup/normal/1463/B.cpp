#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;

int n;
int a[N], b[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		int sum = 0;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			sum += a[i];
		}
		int val1 = 0, val2 = 0;
		for(int i = 1; i <= n; i++)
		{
			if(i % 2)
				val1 += abs(a[i] - 1);
			else
				val2 += abs(a[i] - 1);
		}
		if(val1 * 2 <= sum)
		{
			for(int i = 1; i <= n; i++)
			{
				if(i % 2)
					cout << 1 << " ";
				else
					cout << a[i] << " ";
			}
		}
		else
		{
			for(int i = 1; i <= n; i++)
			{
				if(i % 2)
					cout << a[i] << " ";
				else
					cout << 1 << " ";
			}
		}
		cout << endl;
	}
	return 0;
}