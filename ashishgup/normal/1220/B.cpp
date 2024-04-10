#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1005;

int n;
int a[N][N], b[N];

int get(int x)
{
	int ans = sqrt(x);
	for(int i = ans - 1; i <= ans + 1; i++)
	{
		if(i * i == x)
			return i;
	}
}

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> a[i][j];
	int x = a[1][2];
	int y = a[2][3];
	int z = a[1][3];
	int a2 = x * y / z;
	b[2] = get(a2);
	for(int i = 1; i <= n; i++)
	{
		if(i == 2)
			continue;
		b[i] = a[2][i] / b[2];
	}
	for(int i = 1; i <= n; i++)
		cout << b[i] << " ";
	return 0;
}