#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	int n, m, k;
	cin >> n >> m >> k;
	if(m >= n && k >= n)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}