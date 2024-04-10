#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 1e6 + 5;

int n;
string s[N];
map<int, map<int, vector<string> > > v;

bool isVowel(char ch)
{
	if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
		return 1;
	return 0;
}

int cnt(string &s)
{
	int cnt = 0;
	for(int i = 0; i < s.size(); i++)
		if(isVowel(s[i]))
			cnt++;
	return cnt;
}

char getLast(string &s)
{
	for(int i = s.size() - 1; i >= 0; i--)
		if(isVowel(s[i]))
			return s[i];
}

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i];
		v[cnt(s[i])][getLast(s[i]) - 'a'].push_back(s[i]);
	}
	vector<string> f, s;
	for(int i = 1; i <= n; i++)
	{
		vector<string> temp;
		for(int j = 0; j <= 25; j++)
		{
			while(v[i][j].size() > 1)
			{
				s.push_back(v[i][j].back());
				v[i][j].pop_back();
				s.push_back(v[i][j].back());
				v[i][j].pop_back();
			}
			if(v[i][j].size())
				temp.push_back(v[i][j].back());
		}
		while(temp.size() > 1)
		{
			f.push_back(temp.back());
			temp.pop_back();
			f.push_back(temp.back());
			temp.pop_back();
		}
	}
	vector<string> ans;
	while(s.size() >= 2)
	{	
		if(f.size() >= 2)
		{
			ans.push_back(f.back());
			f.pop_back();
			ans.push_back(s.back());
			s.pop_back();
			ans.push_back(f.back());
			f.pop_back();
			ans.push_back(s.back());
			s.pop_back();
		}
		else if(s.size() >= 4)
		{
			int sz = s.size();
			ans.push_back(s[sz - 1]);
			ans.push_back(s[sz - 3]);
			ans.push_back(s[sz - 2]);
			ans.push_back(s[sz - 4]);
			s.pop_back();
			s.pop_back();
			s.pop_back();
			s.pop_back();
		}
		else
			break;
	}
	cout << ans.size() / 4 << endl;
	for(int i = 0; i < ans.size(); i += 2)
		cout << ans[i] << " " << ans[i + 1] << endl;
	return 0;
}