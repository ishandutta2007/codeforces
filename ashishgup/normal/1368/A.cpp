#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		int a, b, n;
		cin >> a >> b >> n;
		int cnt = 0;
		while(max(a, b) <= n)
		{
			if(a > b)
				swap(a, b);
			a += b;
			cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}