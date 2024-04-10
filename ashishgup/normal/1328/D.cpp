#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n;
int a[N], col[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		map<int, int> m;
		cin >> n;
		int flag = 0;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			m[a[i]]++;
			if(m[a[i]] == n)
				flag = 1;
		}
		if(flag)
		{
			cout << 1 << endl;
			for(int i = 1; i <= n; i++)
				cout << 1 << " ";
			cout << endl;
			continue;
		}
		if(n % 2 == 0)
		{
			cout << 2 << endl;
			for(int i = 1; i <= n; i++)
				cout << ((i % 2)? 1 : 2) << " ";
			cout << endl;
			continue;
		}
		int cnt = 0;
		for(int i = 2; i <= n; i++)
			cnt += (a[i] != a[i - 1]);
		cnt += (a[n] != a[1]);
		if(cnt == n)
		{
			cout << 3 << endl;
			for(int i = 1; i <= n - 1; i++)
				cout << ((i % 2)? 1 : 2) << " ";
			cout << 3;
			cout << endl;
			continue;
		}
		cout << 2 << endl;
		int col = 1, changed = 0;
		for(int i = 1; i <= n; i++)
		{
			cout << col << " ";
			if(i + 1 <= n && a[i + 1] == a[i] && !changed)
			{
				changed = 1;
				continue;
			}
			if(col == 1)
				col = 2;
			else
				col = 1;
		}
		cout << endl;
	}
	return 0;
}