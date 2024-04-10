#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

string a, b;

int32_t main()
{
	IOS;
	cin >> a >> b;
	if(a == b)
		cout << -1;
	else
		cout << max(a.size(), b.size());
	return 0;
}