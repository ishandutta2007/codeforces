#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1005;

int n;
int a[N][N];

void work()
{
	bool check = 1;
	for(int i = 1; i <= n; i++)
	{
		int cur = 0;
		for(int j = 1; j <= n; j++)
			cur ^= a[i][j];
		if(cur > 0)
		{
			check = 0;
			break;
		}
	}
	for(int j = 1; j <= n; j++)
	{
		int cur = 0;
		for(int i = 1; i <= n; i++)
			cur ^= a[i][j];
		if(cur > 0)
		{
			check = 0;
			break;
		}
	}
	if(check)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
				cout << a[i][j] << " ";
			cout << endl;
		}
		exit(0);
	}	
}

int take[4][4];

int32_t main()
{
	IOS;
	cin >> n;
	int cur = 0;
	for(int i = 1; i <= 4; i++)
		for(int j = 1; j <= 4; j++)
			take[i % 4][j % 4] = cur++;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			a[i][j] = take[i % 4][j % 4];
			take[i % 4][j % 4] += 16;
		}
	}
	work();
	return 0;
}