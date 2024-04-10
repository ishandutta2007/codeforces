#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 400;
 
int n;
int m[N], f[N];
 
int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		char ch;
		cin >> ch;
		int l, r;
		cin >> l >> r;
		if(ch == 'M')
			m[l]++, m[r + 1]--;
		else
			f[l]++, f[r + 1]--;
	}
	int ans = 0;
	for(int i = 1; i <= 370; i++)
	{
		m[i] += m[i - 1];
		f[i] += f[i - 1];
		ans = max(ans, min(m[i], f[i]));
	}
	cout << ans * 2;
	return 0;
}