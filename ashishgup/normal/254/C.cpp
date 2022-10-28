#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;
 
string s, t;
 
void upd(map<int, int> &m, char x)
{
	m[x]--;
	if(m[x] == 0)
		m.erase(x);
}
 
int32_t main()
{
	IOS;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> s >> t;
	map<char, int> m;
	map<int, int> extra, need, tot;
	for(auto &it:s)
	{
		tot[it]++;
		m[it]++;
	}
	for(auto &it:t)	
		m[it]--;
	int reqd = 0;
	for(auto &it:m)
	{
		if(it.second > 0)
		{
			reqd += it.second;
			extra[it.first] += it.second;
		}
		else if(it.second < 0)
			need[it.first] += -it.second;
	}
	cout << reqd << endl;
	for(auto &it:s)
	{
		if(extra.find(it) == extra.end())
			cout << it;
		else
		{
			if((need.begin() -> first < it) || (tot[it] == extra[it]))
			{
				upd(extra, it);
				char ch = need.begin() -> first;
				upd(need, ch);
				cout << ch;
			}
			else
				cout << it;
		}
		tot[it]--;
	}
	return 0;
}