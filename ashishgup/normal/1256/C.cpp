#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int c[N], a[N];
int suf[N];
int ans[N];

int32_t main()
{
	IOS;
	int n, m, d;
	cin >> n >> m >> d;
	for(int i = 1; i <= m; i++)
		cin >> c[i];
	for(int i = m; i >= 1; i--)
		suf[i] = suf[i + 1] + c[i];
	int idx = 1;
	int i;
	for(i = d; i <= n; i += d)
	{
		int rhs = n - i;
		bool flag = 0;
		for(int j = idx; j <= m; j++)
		{
			int reqd = suf[j + 1];
			if(reqd > rhs)
				continue;
			flag = 1;
			int shift = rhs - reqd;
			shift = min(shift, c[j] - 1);
			for(int k = i + shift; k >= i + shift - c[j] + 1; k--)
				ans[k] = j;
			int curI = i + shift - c[j];
			for(int p = j - 1; p >= idx; p--)
			{
				int len = c[p];
				while(len > 0)
				{
					ans[curI] = p;
					curI--;
					len--;
				}
			}
			i += shift;
			idx = j + 1;
			break;
		}
		if(!flag)
		{
			cout << "NO";
			return 0;
		}
	}
	if(i <= n)
	{
		cout << "NO";
		return 0;
	}
	int curI = n;
	for(int p = m; p >= idx; p--)
	{
		int len = c[p];
		while(len > 0)
		{
			ans[curI] = p;
			curI--;
			len--;
		}
	}
	cout << "YES" << endl;
	for(int i = 1; i <= n; i++)
		cout << ans[i] << " ";
	return 0;
}