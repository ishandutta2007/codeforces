#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int32_t main()
{
	IOS;
	int val = 0;
	int n;
	cin >> n;
	vector<int> v;
	int cnt = 0, cur = 1;
	multiset<int> pos;
	while(n--)
	{
		string s;
		cin >> s;
		if(s == "for")
		{
			int x;
			cin >> x;
			v.push_back(x);
			if(x > 1)
				pos.insert(x);
			cnt += (x > 1);
		}
		else if(s == "add")
		{
			if(cnt > 50)
			{
				cout << "OVERFLOW!!!";
				exit(0);
			}
			int cur = 1;
			for(auto &it:pos)
			{
				cur *= it;
				if(cur > 1e12)
					cur = 1e12;
			}
			val += cur;
		}
		else
		{
			cnt -= (v.back() > 1);
			if(v.back() > 1)
				pos.erase(pos.find(v.back()));
			v.pop_back();
		}
		if(val >= (1LL << 32))
		{
			cout << "OVERFLOW!!!";
			return 0;
		}
	}
	cout << val;
	return 0;
}