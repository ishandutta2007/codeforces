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
	set<int> v = {6, 10, 14};
	int sum = 0;
	for(auto &it:v)
		sum += it;
	while(t--)
	{
		int n;
		cin >> n;
		if(n <= sum)
			cout << "NO" << endl;
		else
		{
			cout << "YES" << endl;
			int rem = n - sum;
			if(v.find(rem) != v.end())
				cout << "6 10 15" << " " << rem - 1 << endl;
			else
			{
				for(auto &it:v)
					cout << it << " ";
				cout << rem << endl;
			}
		}
	}
	return 0;
}