#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1005;

int n;
int a[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		int l = 1, r = n;
		int sumA = 0, sumB = 0;
		int prv = 0, player = 0, cur = 0;
		int cnt = 1;
		while(l <= r)
		{
			if(player == 0)
			{
				sumA += a[l];
				cur += a[l++];
				if(cur > prv)
				{
					prv = cur;
					cur = 0;
					player ^= 1;
					if(l <= r)
						cnt++;
				}
			}
			else
			{
				sumB += a[r];
				cur += a[r--];
				if(cur > prv)
				{
					prv = cur;
					cur = 0;
					player ^= 1;
					if(l <= r)
						cnt++;
				}
			}
		}
		cout << cnt << " " << sumA << " " << sumB << endl;
	}
	return 0;
}