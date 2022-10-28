#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n;
string s, t;
map<pair<char, char>, vector<int> > m;
vector<int> ab, ba;

int32_t main()
{
	IOS;
	cin >> n >> s >> t;
	for(int i = 0; i < n; i++)
		m[{s[i], t[i]}].push_back(i);
	vector<pair<int, int> > v;
	for(int i = 0; i + 1 < m[{'a', 'b'}].size(); i += 2)
		v.push_back({m[{'a', 'b'}][i], m[{'a', 'b'}][i + 1]});
	for(int i = 0; i + 1 < m[{'b', 'a'}].size(); i += 2)
		v.push_back({m[{'b', 'a'}][i], m[{'b', 'a'}][i + 1]});
	if(m[{'a', 'b'}].size() % 2)
		ab.push_back(m[{'a', 'b'}].back());
	if(m[{'b', 'a'}].size() % 2)
		ba.push_back(m[{'b', 'a'}].back());
	if(ab.size() != ba.size())
	{
		cout << "-1";
		return 0;
	}
	if(ab.size())
	{
		v.push_back({ab.back(), ab.back()});
		v.push_back({ab.back(), ba.back()});
	}
	cout << v.size() << endl;
	for(auto &it:v)
		cout << it.first + 1 << " " << it.second + 1 << endl;
	return 0;
}