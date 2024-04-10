#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n;

int32_t main()
{
	IOS;
	int q;
	cin >> q;
	while(q--)
	{
		cin >> n;
		multiset<int> s;
		bool check = 0;
		for(int i = 1; i <= n; i++)
		{
			int x;
			cin >> x;
			check |= (x == 2048);
			s.insert(x);
		}
		while(s.size() > 1)
		{	
			auto x = *s.begin();
			s.erase(s.find(x));
			auto y = *s.begin();
			s.erase(s.find(y));
			if(x == 2048)
				check = 1;
			else if(y == 2048)
				check = 1;
			if(x == y)
				s.insert(x + y);
			else
				s.insert(y);
		}
		if(*s.begin() == 2048)
			check = 1;
		if(check)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}