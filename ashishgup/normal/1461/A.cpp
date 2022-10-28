#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		int n, k;
		cin >> n >> k;
		for(int i = 0; i < n; i++)
		{
			int cur = i % 3;
			cout << (char)('a' + cur);
		}
		cout << endl;
	}
	return 0;
}