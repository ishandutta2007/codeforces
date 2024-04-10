#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, m;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		int answer = n * (n + 1) / 2;
		n -= m;
		int have = n / (m + 1);
		int quant0 = n % (m + 1);
		int val0 = have + 1;
		int quant1 = ((m + 1) - quant0);
		int val1 = have;
		int ans = (val0 * (val0 + 1)) / 2 * quant0;
		ans += (val1 * (val1 + 1)) / 2 * quant1;
		answer -= ans;
		cout << answer << endl;
	}
	return 0;
}