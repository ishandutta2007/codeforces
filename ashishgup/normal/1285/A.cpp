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
	int l = 0, r = 0;
	for(auto &it:s)
	{
		l += (it == 'L');
		r += (it == 'R');
	}
	cout << r + l + 1;
	return 0;
}