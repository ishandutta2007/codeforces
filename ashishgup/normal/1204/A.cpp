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
	int n = s.size();
	int ans = (n + 1) / 2;
	int check = 1;
	for(int i = 1; i < n; i++)
		check &= (s[i] == '0');
	check &= (n % 2 == 1);
	ans -= check;
	cout << ans;
	return 0;
}