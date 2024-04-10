#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 205;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		vector<int> v;
		int n;
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			int x;
			cin >> x;
			x--;
			v.push_back(x);
		}
		bool check = 0;
		bool flag = 1;
		for(int i = 0; i < v.size(); i++)
		{
			int prv = v[(i - 1 + n) % n];
			int cur = v[i];
			flag &= (cur == (prv + 1) % n);
		}
		check |= flag;
		reverse(v.begin(), v.end());
		flag = 1;
		for(int i = 0; i < v.size(); i++)
		{
			int prv = v[(i - 1 + n) % n];
			int cur = v[i];
			flag &= (cur == (prv + 1) % n); 
		}
		check |= flag;
		if(check)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}