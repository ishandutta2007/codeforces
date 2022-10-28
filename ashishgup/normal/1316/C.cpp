#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e6 + 5;

int n, m, p, idxI = -1, idxJ = -1;
int a[N], b[N];

int32_t main()
{
	IOS;
	cin >> n >> m >> p;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		if(a[i] % p && idxI == -1)
			idxI = i;
	}
	for(int i = 0; i < m; i++)
	{
		cin >> b[i];
		if(b[i] % p && idxJ == -1)
			idxJ = i;
	}
	cout << idxI + idxJ;
	return 0;
}