#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;

int n;
int a[N][6];

int comp(int i, int j)
{
	int cnt = 0;
	for(int k = 1; k <= 5; k++)
		cnt += (a[i][k] < a[j][k]);
	if(cnt >= 3)
		return i;
	else
		return j;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= 5; j++)
				cin >> a[i][j];
		}
		if(n == 1)
		{
			cout << 1 << endl;
			continue;
		}
		int candidate = 1;
		for(int i = 2; i <= n; i++)
			candidate = comp(candidate, i);
		int flag = 1;
		for(int i = 1; i <= n; i++)
		{
			if(i == candidate)
				continue;
			if(comp(i, candidate) != candidate)
				flag = 0;
		}
		if(!flag)
			cout << -1 << endl;
		else
			cout << candidate << endl;
	}
	return 0;
}