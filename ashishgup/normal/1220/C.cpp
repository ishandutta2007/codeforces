#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	string s;
	cin >> s;
	char ch = 'z';
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] > ch)
			cout << "Ann" << endl;
		else
			cout << "Mike" << endl;
		ch = min(ch, s[i]);
	}	
	return 0;
}