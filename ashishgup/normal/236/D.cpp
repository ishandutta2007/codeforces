#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n;
double p[N], dpLen[N], dpScore[N];

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> p[i];
		dpLen[i] = p[i] * (1 + dpLen[i - 1]);
		dpScore[i] = (1 - p[i]) * dpScore[i - 1] + p[i] * (dpScore[i - 1] + 2 * dpLen[i - 1] + 1);
	}
	cout << fixed << setprecision(12) << dpScore[n];
	return 0;
}