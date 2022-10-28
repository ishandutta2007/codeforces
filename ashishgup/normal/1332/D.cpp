#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int k;
int a[5][5];

int32_t main()
{
	IOS;
	cin >> k;
	if(k == 0)
	{
		cout << 1 << " " << 1 << endl;
		cout << 1;
		return 0;
	}
	cout << 2 << " " << 3 << endl;
	int pw2 = 1, mx = 1;
	while(pw2 <= k)
	{
		pw2 *= 2;
		mx += pw2;
	}
	mx += pw2 * 2;
	int x = k;
	a[2][3] = x;
	a[1][3] = 0;
	a[1][2] = x;
	int y = x;
	int flag = 0;
	int other = -x;
	y += pw2;
	a[1][1] = y;
	a[2][2] = y;
	other += y;
	a[2][1] = other;
	for(int i = 1; i <= 2; i++)
	{
		for(int j = 1; j <= 3; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	return 0;
}