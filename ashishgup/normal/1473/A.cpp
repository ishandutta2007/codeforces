//Trying to screencast

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 105;

int n, d;
int a[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> d;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		sort(a + 1, a + n + 1);
		if(a[n] <= d)
			cout << "YES" << endl;
		else
		{
			if(a[1] + a[2] <= d)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
	return 0;
}