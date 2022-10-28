#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	vector<int> v(4);
	for(int i = 0; i < 4; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	for(int i = 0; i < 3; i++)
		cout << v[3] - v[i] << " ";
	return 0;
}