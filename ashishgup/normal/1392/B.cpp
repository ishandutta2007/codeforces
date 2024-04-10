#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, k;
int a[N];

void work()
{
	int mx = -1e9;
	for(int i = 1; i <= n; i++)
		mx = max(mx, a[i]);
	for(int i = 1; i <= n; i++)
		a[i] = mx - a[i];
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		work();
		k--;
		if(k % 2)
			work();
		for(int i = 1; i <= n; i++)
			cout << a[i] << " ";
		cout << endl;
	}
	return 0;
}