#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e6 + 5;

int n, m;
int x[N], y[N];

int32_t main()
{
	IOS;
	cin >> n >> m;
	int curx = 1, cury = 1;
	for(int i = 0; i < n * m; i++)
	{
		x[i] = i / m;
		y[i] = i % m;
	}
	int cur = 0;
	for(int i = 0, j = n * m - 1; i <= j;)
	{
		if(!cur)
		{
			cout << x[i] + 1 << " " << y[i] + 1 << endl;
			i++;
		}
		else
		{
			cout << x[j] + 1 << " " << y[j] + 1 << endl;
			j--;
		}
		cur ^= 1;
	}
	return 0;
}