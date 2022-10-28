#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n;
int a[N];
map<int, int> m;

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		m[a[i]]++;
	}
	for(auto &it:m)
	{
		if(it.second >= 3)
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES" << endl;
	int sz = m.size();
	cout << sz << endl;
	vector<int> del;
	for(auto &it:m)
	{
		cout << it.first << " ";
		it.second--;
		if(it.second == 0)
			del.push_back(it.first);
	}
	cout << endl;
	for(auto &it:del)
		m.erase(it);
	cout << m.size() << endl;
	if(m.size())
	{
		auto it = --m.end();
		do
		{
			cout << it->first << " ";
			if(it == m.begin())
				break;
			it--;
		}while(true);
	}
	return 0;
}