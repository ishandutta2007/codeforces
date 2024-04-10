#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;

int n, q;
string s;
int pref[N][26];

int32_t main()
{
	IOS;
	cin >> n >> q;
	cin >> s;
	for(int i = 0; i < 26; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			pref[j][i] = pref[j - 1][i] + ((s[j - 1] - 'a') == i);
		}
	}
	while(q--)
	{
		int l, r;
		cin >> l >> r;
		int ans = 0;
		for(int i = 0; i < 26; i++)
			ans += (i + 1) * (pref[r][i] - pref[l - 1][i]);
		cout << ans << endl;
	}
	return 0;
}