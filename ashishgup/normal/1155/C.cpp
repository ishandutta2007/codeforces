#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 3e5 + 5;

int n, m;
int x[N], p[N];

int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> x[i];
	for(int i = 1; i <= m; i++)
		cin >> p[i];
	int reqd = 0;
	for(int i = 1; i + 1 <= n; i++)
		reqd = __gcd(reqd, x[i + 1] - x[i]);
	for(int i = 1; i <= m; i++)
	{
		if(reqd % p[i] == 0)
		{
			cout << "YES" << endl;
			cout << x[1] << " " << i;
			exit(0);
		}
	}
	cout << "NO";
	return 0;
}