#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;
const int MOD = 998244353;

int n;
int a[N], b[N], c[N], d[N];

int work()
{
	int cur = 0;
	for(int i = 1; i <= n; i++)
	{
		c[i] %= MOD;
		d[i] %= MOD;
		cur += c[i] * d[i];
		cur %= MOD;
	}
	return cur;
}

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		c[i] = a[i] * i * (n - i + 1);
	}
	for(int i = 1; i <= n; i++)
		cin >> b[i];
	sort(c + 1, c + n + 1);
	for(int i = 1; i <= n; i++)
		d[i] = b[i];
	sort(d + 1, d + n + 1);
	reverse(d + 1, d + n + 1);
	cout << work();
	return 0;
}