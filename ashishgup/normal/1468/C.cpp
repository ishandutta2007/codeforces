#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
 
const int N = 2e5 + 5;

int32_t main()
{
	IOS;
	int q;
	cin >> q;
	int ctr = 0;
	map<int, queue<int> > m;
	set<int> have;
	while(q--)
	{
		int type;
		cin >> type;
		if(type == 1)
		{
			ctr++;
			have.insert(ctr);
			int val;
			cin >> val;
			m[val].push(ctr);
		}
		else if(type == 2)
		{
			int val = *have.begin();
			cout << val << " ";
			have.erase(val);
		}
		else
		{
			int val = -1;
			while(val == -1)
			{
				auto it = m.rbegin();
				if(have.find(it->second.front()) == have.end())
				{
					it->second.pop();
					if(it->second.size() == 0)
						m.erase(it->first);
				}
				else
				{
					val = it->second.front();
					it->second.pop();
					if(it->second.size() == 0)
						m.erase(it->first);
					have.erase(val);
				}
			}
			cout << val << " ";
		}
	}
	return 0;
}