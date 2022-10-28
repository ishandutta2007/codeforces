#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 3e5 + 5;

int n, p, k, MOD;
int a[N];
map<int, int> m;

int get(int x)
{
	int val = x * x;
	val %= MOD;
	val *= val;
	val %= MOD;
	val -= (k * x) % MOD;
	val += MOD;
	val %= MOD;
	return val;
}

int32_t main()
{
	IOS;
	cin >> n >> p >> k;
	MOD = p;
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		int x = get(a[i]);
		ans += m[x];
		m[x]++;
	}
	cout << ans;
	return 0;
}