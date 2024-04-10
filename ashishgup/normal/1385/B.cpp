#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 105;

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
		map<int, int> vis;
		for(int i = 1; i <= 2 * n; i++)
		{
			cin >> a[i];
			if(!vis[a[i]])
				cout << a[i] << " ";
			vis[a[i]] = 1;
		}
		cout << endl;
	}
	return 0;
}