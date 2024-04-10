#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n;
string s;

int32_t main()
{
	IOS;
	cin >> n >> s;
	string cur = "";
	for(int i = 0; i < n; i++)
	{
		if(s[i] != cur.back() || cur.size() % 2 == 0)
			cur += s[i];
	}
	if(cur.size() % 2)
		cur.pop_back();
	cout << n - cur.size() << endl;
	cout << cur;
	return 0;
}