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
		string s;
		cin >> s;
		int sum = 0, have = 0, even = 0;
		for(auto &it:s)
		{
			sum += (it - '0');
			have += (it == '0');
			even += ((it - '0') % 2 == 0);
		}
		if(sum == 0)
		{
			cout << "red" << endl;
			continue;
		}
		if(sum % 3 == 0 && have && even > 1)
			cout << "red" << endl;
		else
			cout << "cyan" << endl;
	}
	return 0;
}