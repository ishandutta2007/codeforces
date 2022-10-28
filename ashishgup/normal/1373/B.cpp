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
		string s;
		cin >> s;
		int ct0 = 0, ct1 = 0;
		for(auto &it:s)
			ct0 += (it == '0'), ct1 += (it == '1');
		if(min(ct0, ct1) % 2)
			cout << "DA" << endl;
		else
			cout << "NET" << endl;
	}
	return 0;
}