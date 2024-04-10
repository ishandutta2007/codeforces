#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n;
int a[N], ans[N], idx[30];

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 0; i < 30; i++)
		idx[i] = 1;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		for(int j = 20; j >= 0; j--)
		{
			if(a[i] >> j & 1)
				ans[idx[j]++] |= (1LL << j);
		}
	}
	int answer = 0;
	for(int i = 1; i <= n; i++)
		answer += (ans[i] * ans[i]);
	cout << answer;
	return 0;
}