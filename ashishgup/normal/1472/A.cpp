//Trying to screencast

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;

int recurse(int w, int h)
{
	if(w % 2 == 0)
		return 2 * recurse(w / 2, h);
	if(h % 2 == 0)
		return 2 * recurse(w, h / 2);
	return 1;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		int w, h, n;
		cin >> w >> h >> n;
		int mx = recurse(w, h);
		if(mx >= n)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}