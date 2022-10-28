#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

string s, t;

void check(string &str)
{
	for(int i = 0; i + 1 < str.size(); i++)
	{
		string a = "";
		a += str[i];
		a += str[i + 1];
		if(a == s || a == t)
			return;
	}
	cout << "YES" << endl;
	cout << str;
	exit(0);
}

int32_t main()
{
	IOS;
	int n;
	cin >> n;
	cin >> s >> t;
	vector<char> v;
	v.push_back('a');
	v.push_back('b');
	v.push_back('c');
	do
	{
		string s = "";
		string t = "";
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < n; j++)
				s += v[i];
		for(int i = 0; i < 3 * n; i++)
			t += v[i % 3];
		check(s);
		check(t);

	}while(next_permutation(v.begin(), v.end()));
	cout << "NO";
	return 0;
}