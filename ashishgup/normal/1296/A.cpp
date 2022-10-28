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
		int o = 0, e = 0;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			o += (a[i] % 2);
		}
		e = n - o;
		if(o % 2)
			cout << "YES" << endl;
		else
		{
			if(o >= 1 && e >= 1)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	return 0;
}