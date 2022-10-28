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
		int n;
		cin >> n;
		set<int> s;
		for(int i = 1; i <= n; i++)
		{
			int x;
			cin >> x;
			s.insert(x % 2);
		}
		if(s.size() == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}