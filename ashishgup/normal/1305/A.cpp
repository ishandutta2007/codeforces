#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n;
pair<int, int> a[N], b[N];

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
			cin >> a[i].first;
			a[i].second = i;
		}
		for(int i = 1; i <= n; i++)
		{
			cin >> b[i].first;
			b[i].second = i;
		}
		sort(a + 1, a + n + 1);
		sort(b + 1, b + n + 1);
		for(int i = 1; i <= n; i++)
			cout << a[i].first << " ";
		cout << endl;
		for(int i = 1; i <= n; i++)
			cout << b[i].first << " ";
		cout << endl;
	}
	return 0;
}