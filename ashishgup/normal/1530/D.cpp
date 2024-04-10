#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;

int n;
int a[N], ans[N];
vector<int> store[N];

int getVal()
{
	int ct = 0;
	for(int i = 1; i <= n; i++)
	{
		assert(i != ans[i]);
		ct += (a[i] == ans[i]);
	}
	return ct;
}

void put(set<int> &s, vector<int> &v)
{
	if(v.size() == 0)
		return;
	while(v.size() > 2)
	{
		int x = v.back();
		v.pop_back();
		int y;
		for(auto &it:s)
		{
			if(it != x)
			{
				y = it;
				break;
			}
		}
		s.erase(y);
		ans[x] = y;
	}
	int x1 = v[0], x2 = v[1];
	auto it = s.begin();
	int y1 = *it;
	it++;
	int y2 = *it;
	if(y1 == x1 || y2 == x2)
		swap(y1, y2);
	ans[x1] = y1;
	ans[x2] = y2;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
			store[i].clear();
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			ans[i] = -1;
			store[a[i]].push_back(i);
		}
		int val = 0;
		for(int i = 1; i <= n; i++)
			val += min(1LL, (int)store[i].size());
		if(val != n - 1)
		{
			set<int> s;
			for(int i = 1; i <= n; i++)
				s.insert(i);
			vector<int> v;
			for(int i = 1; i <= n; i++)
			{
				if(store[i].size())
				{
					ans[store[i][0]] = i;
					s.erase(i);
				}
				for(int j = 1; j < store[i].size(); j++)
					v.push_back(store[i][j]);
			}
			put(s, v);
		}
		else
		{
			set<int> s;
			for(int i = 1; i <= n; i++)
				s.insert(i);
			vector<int> v;
			for(int i = 1; i <= n; i++)
			{
				if(store[i].size() == 1)
				{
					ans[store[i][0]] = i;
					s.erase(i);
				}
				else
				{
					for(int j = 0; j < store[i].size(); j++)
						v.push_back(store[i][j]);
				}
			}
			put(s, v);
		}
		int val2 = getVal();
		assert(val == val2);
		cout << val2 << endl;
		for(int i = 1; i <= n; i++)
			cout << ans[i] << " ";
		cout << endl;
	}
	return 0;
}