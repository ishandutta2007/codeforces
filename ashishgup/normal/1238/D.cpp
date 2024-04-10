#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 3e5 + 5;

int n;
string s;

int32_t main()
{
	IOS;
	cin >> n >> s;
	int ans = n * (n + 1) / 2;
	ans -= n;
	vector<int> lens;
	for(int i = 0; i < n;)
	{
		int j = i;
		while(j < n && s[i] == s[j])
			j++;
		lens.push_back(j - i);
		i = j;
	}
	for(int i = 0; i + 1 < lens.size(); i++)
	{
		int x = lens[i];
		int y = lens[i + 1];
		ans -= y;
		ans -= x;
		ans++;
	}
	cout << ans;
	return 0;
}