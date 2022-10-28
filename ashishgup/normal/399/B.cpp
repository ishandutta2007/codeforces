#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;
 
int n, ans = 0;
string s;
int cnt[N];
 
int32_t main()
{
	IOS;
	cin >> n >> s;
	for(int i = 1; i <= n; i++)
	{
		cnt[i] = 1;
		for(int j = 0; j < i; j++)
			cnt[i] += cnt[j];
		if(s[i - 1] == 'B')
			ans += cnt[i];
	}
	cout << ans;
	return 0;
}