#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n;
string s;
bool vis[N];
vector<pair<char, int> > v;

bool check(vector<pair<char, int> > &v)
{
	int sz = v.size();
	for(int i = 1; i < sz; i++)
		if(v[i - 1].first == '(' && v[i].first == ')')
			return 1;
	return 0;
}

bool comp(pair<char, int> &a, pair<char, int> &b)
{
	return a.second < b.second;
}

int32_t main()
{
	IOS;
	cin >> s;
	n = s.size();
	for(int i = 0; i < n; i++)
		v.push_back({s[i], i});
	vector<vector<int> > ans;
	while(check(v))
	{
		vector<pair<char, int> > nv;
		int sz = v.size();
		int i = 0, j = sz - 1;
		vector<int> cur;
		while(i < j)
		{
			if(v[i].first == ')')
			{
				nv.push_back({v[i].first, i});
				i++;
				continue;
			}
			if(v[j].first == '(')
			{
				nv.push_back({v[j].first, j});
				j--;
				continue;
			}
			cur.push_back(v[i].second);
			cur.push_back(v[j].second);
			i++;
			j--;
		}
		sort(nv.begin(), nv.end(), comp);
		v = nv;
		sort(cur.begin(), cur.end());
		ans.push_back(cur);
	}
	cout << ans.size() << endl;
	for(auto &it:ans)
	{
		cout << it.size() << endl;
		for(auto &j:it)
			cout << j + 1 << " ";
		cout << endl;
	}
	return 0;
}