#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1.5e5 + 5;

int n;
string s;

int get(int l, int r, char ch)
{
	if(l == r)
		return (s[l] != ch);
	int m = (l + r) / 2;
	int lcost = get(m + 1, r, (char)(ch + 1));
	int rcost = get(l, m, (char)(ch + 1));
	for(int i = l; i <= m; i++)
		lcost += (s[i] != ch);
	for(int i = m + 1; i <= r; i++)
		rcost += (s[i] != ch);
	return min(lcost, rcost);
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> s;
		int ans = get(0, n - 1, 'a');
		cout << ans << endl;
	}
	return 0;
}