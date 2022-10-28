#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		string s;
		cin >> n >> s;
		for(int i = 0; i < n; i++)
		{
			if(s[i] == 'U')
				cout << "D";
			if(s[i] == 'D')
				cout << "U";
			if(s[i] == 'L')
				cout << "L";
			if(s[i] == 'R')
				cout << "R";
		}
		cout << endl;
	}
	return 0;
}