#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;

set<int> divs;
map<int, vector<int> > store;

vector<pair<int, int> > get(int n)
{
	vector<pair<int, int> > v;
	for(int i = 1; i * i <= n; i++)
		if(n % i == 0)
			divs.insert(i), divs.insert(n / i);
	divs.erase(1);
	for(int i = 2; i * i <= n; i++)
	{
		if(n % i)
			continue;
		int ct = 0;
		while(n % i == 0)
		{
			ct++;
			n /= i;
		}
		v.push_back({i, ct});
	}
	if(n > 1)
		v.push_back({n, 1});
	for(auto &it:divs)
	{
		for(auto &p:v)
		{
			if(it % p.first == 0)
			{
				store[p.first].push_back(it);
				break;
			}
		}
	}
	return v;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		divs.clear();
		store.clear();
		int n;
		cin >> n;
		vector<pair<int, int> > v = get(n);
		if(v.size() == 1)
		{
			for(auto &it:divs)
				cout << it << " ";
			cout << endl;
			cout << 0 << endl;
			continue;
		}
		else if(v.size() == 2)
		{
			if(v[0].second == 1 && v[1].second == 1)
			{
				for(auto &it:divs)
					cout << it << " ";
				cout << endl;
				cout << 1 << endl;
			}
			else
			{
				if(v[0].second < v[1].second)
					swap(v[0], v[1]);
				int p = v[0].first;
				int val = 1;
				for(int i = 1; i <= v[0].second; i++)
				{
					val *= p;
					cout << val << " ";
					divs.erase(val);
				}
				cout << v[0].first * v[1].first << " ";
				divs.erase(v[0].first * v[1].first);
				p = v[1].first;
				val = 1;
				for(int i = 1; i <= v[1].second; i++)
				{
					val *= p;
					cout << val << " ";
					divs.erase(val);
				}
				for(auto &it:divs)
					cout << it << " ";
				cout << endl;
				cout << 0 << endl;
			}
		}
		else
		{
			for(int i = 0; i < v.size(); i++)
				divs.erase(v[i].first * v[(i + 1) % v.size()].first);
			for(int i = 0; i < v.size(); i++)
			{
				int p = v[i].first;
				int val = 1;
				for(int j = 1; j <= v[i].second; j++)
				{
					val *= p;
					cout << val << " ";
					divs.erase(val);
				}
				for(auto &it:store[p])
				{
					if(divs.find(it) != divs.end())
					{
						cout << it << " ";
						divs.erase(it);
					}
				}
				cout << v[i].first * v[(i + 1) % v.size()].first << " ";
			}
			assert(divs.size() == 0);
			for(auto &it:divs)
				cout << it << " ";
			cout << endl;
			cout << 0 << endl;
		}
	}
	return 0;
}