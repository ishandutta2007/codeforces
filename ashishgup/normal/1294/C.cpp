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
		vector<int> v;
		for(int i = 2; i * i <= n; i++)
		{
			while(n % i == 0)
			{
				v.push_back(i);
				n /= i;
			}
		}
		if(n > 1)
			v.push_back(n);
		set<int> s;
		int cur = 1;
		for(auto &it:v)
		{
			cur *= it;
			if(s.size() <= 1 && s.find(cur) == s.end())
			{
				s.insert(cur);
				cur = 1;
			}
		}
		if(cur == 1 || s.find(cur) != s.end())
			cout << "NO" << endl;
		else
		{
			s.insert(cur);
			cout << "YES" << endl;
			for(auto &it:s)
				cout << it << " ";
			cout << endl;
		}
	}
	return 0;
}