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
		cin >> n;
		vector<int> ans;
		for(int i = 0; i < n; i++)
			ans.push_back(9);
		int rem = (n + 3) / 4;
		for(int i = n - 1; i >= n - rem; i--)
			ans[i] = 8;
		for(auto &it:ans)
			cout << it;
		cout << endl;
	}
	return 0;
}