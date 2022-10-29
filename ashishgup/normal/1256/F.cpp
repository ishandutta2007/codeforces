#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int f[26], f2[26];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		memset(f, 0, sizeof(f));
		memset(f2, 0, sizeof(f2));
		int n;
		cin >> n;
		string s, t;
		cin >> s >> t;
		string a = s;
		string b = t;
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		if(a != b)
		{
			cout << "NO" << endl;
			continue;
		}
		map<char, int> m1, m2;
		for(auto &it:s)
			m1[it]++;
		for(auto &it:t)
			m2[it]++;
		bool printed = 0;
		for(auto &it:m1)
		{
			if(it.second > 1)
			{
				cout << "YES" << endl;
				printed = 1;
				break;
			}
		}
		if(printed)
			continue;
		for(auto &it:m2)
		{
			if(it.second > 1)
			{
				cout << "YES" << endl;
				printed = 1;
				break;
			}
		}
		if(printed)
			continue;
		int inv1 = 0, inv2 = 0;
		for(int i = 0; i < n; i++)
		{
			for(int j = s[i] - 'a' - 1; j >= 0; j--)
				inv1 += f[j];
			for(int j = t[i] - 'a' - 1; j >= 0; j--)
				inv2 += f2[j];
			f[s[i] - 'a']++;
			f2[t[i] - 'a']++;
		}
		if(inv1 % 2 == inv2 % 2)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}