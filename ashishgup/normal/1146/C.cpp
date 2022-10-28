#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int diameter = 0;
		for(int i = 0; i < 9; i++)
		{
			vector<int> v1, v2;
			for(int j = 1; j <= n; j++)
			{
				if(j >> i & 1)
					v1.push_back(j);
				else
					v2.push_back(j);
			}
			if(!v1.size())
				continue;
			if(!v2.size())
				continue;
			cout << v1.size() << " " << v2.size() << " ";
			for(auto &it:v1)
				cout << it << " ";
			for(auto &it:v2)
				cout << it << " ";
			cout << endl;
			int x;	
			cin >> x;
			diameter = max(diameter, x);
		}
		cout << -1 << " " << diameter << endl;
	}
	return 0;
}