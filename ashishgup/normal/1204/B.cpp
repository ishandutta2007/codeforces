#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1005;

int n, l, r;
int mn[N], mx[N];

int32_t main()
{
	IOS;
	cin >> n >> l >> r;
	mn[1] = 1;
	for(int i = 2; i <= l; i++)
		mn[i] = mn[i - 1] * 2;
	for(int i = l + 1; i <= n; i++)
		mn[i] = 1;
	mx[1] = 1;
	for(int i = 2; i <= r; i++)
		mx[i] = mx[i - 1] * 2;
	for(int i = r + 1; i <= n; i++)
		mx[i] = mx[i - 1];
	int ans1 = 0, ans2 = 0;
	for(int i = 1; i <= n; i++)
	{
		ans1 += mn[i];
		ans2 += mx[i];
	}
	cout << ans1 << " " << ans2;
	return 0;
}