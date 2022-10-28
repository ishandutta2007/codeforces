#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int32_t main()
{
	IOS;
	vector<int> v;
	v.push_back(3);
	int cur = 4;
	while(cur <= 1e9)
	{
		v.push_back(v.back() + cur);
		cur *= 2;
	}
	reverse(v.begin(), v.end());
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		for(auto &it:v)
		{
			if(n % it == 0)
			{
				cout << n / it << endl;
				break;
			}
		}
	}
	return 0;
}