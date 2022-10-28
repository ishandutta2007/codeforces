#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int32_t main()
{
	IOS;
	string s;
	cin >> s;
	char ch = 'a';
	for(auto &it:s)
	{
		if(it <= ch && ch <= 'z')
		{
			it = ch;
			ch++;
		}
	}
	if(ch <= 'z')
		cout << -1;
	else
		cout << s;
	return 0;
}