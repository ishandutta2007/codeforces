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
		string s;
		cin >> s;
		int flag = 0;
		for(int i = 0; i + 1 < n; i++)
		{
			if(s[i] != s[i + 1])
			{
				flag = 1;
				cout << i + 1 << " " << i + 2 << endl;
				break;
			}
		}
		if(!flag)
			cout << -1 << " " << -1 << endl;
	}
	return 0;
}