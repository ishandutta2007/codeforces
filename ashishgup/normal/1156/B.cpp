#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

map<char, int> f;
vector<char> v;
string ans;

bool check(string &s)
{
	for(int i = 0; i + 1 < s.size(); i++)
	{
		if(abs(s[i] - s[i + 1]) == 1)
			return 0;
	}
	return 1;
}

void brute()
{
	do
	{
		ans = "";
		for(int i = 0; i < v.size(); i++)
		{
			for(int j = 1; j <= f[v[i]]; j++)
				ans += v[i];
		}
		if(check(ans))
			return;
	}while(next_permutation(v.begin(), v.end()));
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		v.clear();
		string s;
		cin >> s;
		f.clear();
		for(auto &it:s)
			f[it]++;
		for(auto &it:f)
			v.push_back(it.first);
		ans = "";
		if(v.size() % 2 == 0)
		{
			for(int i = 1; i < v.size(); i += 2)
			{
				for(int j = 1; j <= f[v[i]]; j++)
					ans += v[i];
			}
			for(int i = 0; i < v.size(); i += 2)
			{
				for(int j = 1; j <= f[v[i]]; j++)
					ans += v[i];
			}
		}
		else
		{
			if(v.size() == 3)
			{
				brute();
			}
			else
			{
				for(int i = 0; i < v.size(); i += 2)
				{
					for(int j = 1; j <= f[v[i]]; j++)
						ans += v[i];
				}
				for(int i = 1; i < v.size(); i += 2)
				{
					for(int j = 1; j <= f[v[i]]; j++)
						ans += v[i];
				}
			}
		}
		if(check(ans))
			cout << ans << endl;
		else
			cout << "No answer" << endl;
	}
	return 0;
}