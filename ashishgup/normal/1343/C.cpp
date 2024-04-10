#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n;
int a[N];

int get(int x)
{
	return a[x] > 0;
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
			cin >> a[i];
		int sum = 0;
		for(int i = 1; i <= n; i++)
		{
			int j = i;
			int mx = a[i];
			while(j + 1 <= n && get(i) == get(j + 1))
			{
				j++;
				mx = max(mx, a[j]);
			}
			sum += mx;
			i = j;
		}
		cout << sum << endl;
	}
	return 0;
}