#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int32_t main()
{
	IOS;
	int n;
	cin >> n;
	set<int> s;
	for(int i = 1; i * (i + 1) / 2 <= 1e9; i++)
		s.insert(i * (i + 1) / 2);
	bool check = 0;
	for(auto &it:s)
		if(it < n && s.find(n - it) != s.end())
			check = 1;
	if(check)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}