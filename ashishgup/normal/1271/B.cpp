#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n;
string s;

int32_t main()
{
	IOS;
	cin >> n >> s;
	int b = 0, w = 0;
	for(auto &it:s)
	{
		b += (it == 'B');
		w += (it == 'W');
	}
	if(w % 2 && b % 2)
	{
		cout << -1;
		return 0;
	}
	vector<int> v;
	for(int i = 0; i + 1 < n; i++)
	{
		if(s[i] == 'B' && w % 2)
		{
			v.push_back(i + 1);
			s[i] = 'W';
			if(s[i + 1] == 'W')
				s[i + 1] = 'B';
			else
				s[i + 1] = 'W';
		}
		else if(s[i] == 'W' && w % 2 == 0)
		{
			v.push_back(i + 1);
			s[i] = 'B';
			if(s[i + 1] == 'W')
				s[i + 1] = 'B';
			else
				s[i + 1] = 'W';
		}
	}
	cerr << s;
	cout << v.size() << endl;
	for(auto &it:v)
		cout << it << " ";
	return 0;
}