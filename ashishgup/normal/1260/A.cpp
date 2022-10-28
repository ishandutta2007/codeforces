#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e3 + 5;

int n;
int c[N], sum[N];

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> c[i] >> sum[i];
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		int x = sum[i] / c[i];
		int y = sum[i] % c[i];
		int z = c[i] - y;
		int val = (x * x) * z + ((x + 1) * (x + 1)) * y;
		cout << val << endl;
	}
	return 0;
}