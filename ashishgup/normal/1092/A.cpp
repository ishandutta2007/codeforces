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
		int n, k;
		cin >> n >> k;
		for(int i = 0; i < n; i++)
		{
			char ch = (char)('a' + (i % k));
			cout << ch;
		}
		cout << endl;
	}
	return 0;
}