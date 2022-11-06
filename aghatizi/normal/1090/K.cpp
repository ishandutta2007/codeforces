#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define bit(a , b) (((a)>>(b))&1)

const int maxn = 1e5 + 20;

string s[maxn] , t[maxn];

vector<int> ans[maxn];

map<pair<string , int> , int> mp;

int id;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> s[i] >> t[i];

	for(int i = 0; i < n; i++)
	{
		int st = 0;
		for(auto ch : t[i])
			st |= (1 << (ch - 'a'));

		bool f = 0;
		for(int j = (int)s[i].size() - 1; j >= 0 && !f; j--)
			if(!bit(st , s[i][j] - 'a'))
			{
				f = 1;
				s[i] = s[i].substr(0 , j + 1);
			}

		if(!f)
			s[i] = "";

		auto tmp = make_pair(s[i] , st);
		
		if(!mp.count(tmp))
			mp[tmp] = id++;

		ans[mp[tmp]].pb(i);
	}

	cout << id << endl;
	for(int i = 0; i < id; i++)
	{
		cout << ans[i].size() << " ";
		for(auto ind : ans[i])
			cout << ind + 1 << " ";
		cout << endl;
	}
	cout << endl;
}