#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e6 + 5;

int n, k;
string s;
int f[N];

int32_t main()
{
	IOS;
	cin >> k >> s;
	n = s.size();
	int cur = 0, ans = 0;
	f[0]++;
	for(int i = 0; i < n; i++)
	{
		cur += (s[i] == '1');
		if(cur - k >= 0)
			ans += f[cur - k];
		f[cur]++;
	}
	cout << ans;
	return 0;
}