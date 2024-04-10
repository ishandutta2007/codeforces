#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 3005;

bool check(string &s, char a, char b, char c)
{
	int ct = 0;
	for(auto &it:s)
	{
		if(it == a)
			ct++;
		else if(it == b)
			ct++;
		else
			ct--;
		if(ct < 0)
			return 0;
	}
	if(ct != 0)
		return 0;
	return 1;
}

bool check2(string &s, char a, char b, char c)
{
	int ct = 0;
	for(auto &it:s)
	{
		if(it == a)
			ct++;
		else if(it == b)
			ct--;
		else
			ct--;
		if(ct < 0)
			return 0;
	}
	if(ct != 0)
		return 0;
	return 1;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		vector<char> v = {'A', 'B', 'C'};
		int ans = 0;
		do
		{
			ans |= check(s, v[0], v[1], v[2]);
			ans |= check2(s, v[0], v[1], v[2]);
		}while(next_permutation(v.begin(), v.end()));
		if(ans)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}