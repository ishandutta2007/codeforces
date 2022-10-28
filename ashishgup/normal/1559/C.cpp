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
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		if(a[1] == 1)
		{
			cout << n + 1 << " ";
			for(int i = 1; i <= n; i++)
				cout << i << " ";
			cout << endl;
			continue;
		}
		if(a[n] == 0)
		{
			for(int i = 1; i <= n + 1; i++)
				cout << i << " ";
			cout << endl;
			continue;
		}
		int flag = 0;
		for(int i = 1; i + 1 <= n && !flag; i++)
		{
			if(a[i] == 0 && a[i + 1] == 1)
			{
				for(int j = 1; j <= i; j++)
					cout << j << " ";
				cout << n + 1 << " ";
				for(int j = i + 1; j <= n; j++)
					cout << j << " ";
				cout << endl;
				flag = 1;
				break;
			}
		}
		if(!flag)
			cout << -1 << endl;
	}
	return 0;
}