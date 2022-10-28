#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

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
		bool flag = 0;
		for(int i = 1; i + 1 <= n; i++)
		{
			if(abs(a[i] - a[i + 1]) >= 2)
			{
				cout << "YES" << endl;
				cout << i << " " << i + 1 << endl;
				flag = 1;
				break;
			}
		}
		if(!flag)
			cout << "NO" << endl;
	}
	return 0;
}