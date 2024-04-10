#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 305;

int n, k;
int a[N][N], rows[N], cols[N];

int sqr(int x)
{
	return x * x;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		for(int i = 0; i < n; i++)
		{
			rows[i] = cols[i] = 0;
			for(int j = 0; j < n; j++)
				a[i][j] = 0;
		}
		int sti = 0, i = 0, j = 0;
		while(k > 0)
		{
			if(a[i][j])
			{
				sti++;
				i = sti, j = 0;
			}
			else
			{
				a[i][j] = 1;
				rows[i]++;
				cols[j]++;
				i++, j++;
				i %= n;	
				j %= n;
				k--;
			}
		}
		int ans = 0;
		sort(rows, rows + n);
		sort(cols, cols + n);
		ans += sqr(rows[n - 1] - rows[0]) + sqr(cols[n - 1] - cols[0]);
		cout << ans << endl;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
				cout << a[i][j];
			cout << endl;
		}
	}
	return 0;
}