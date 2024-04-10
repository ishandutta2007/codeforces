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
	for(int i = 0; i + 1 < n; i++)
	{
		if(s[i + 1] < s[i])
		{
			cout << "YES" << endl;
			cout << i + 1 << " " << i + 2;
			exit(0);
		}
	}
	cout << "NO";
	return 0;
}