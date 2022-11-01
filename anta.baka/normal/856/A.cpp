#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		vector<bool> ban(1000000, false);
		for(int i = 0; i < n; i++)
		{
			for(int j = i + 1; j < n; j++)
			{
				ban[abs(a[i] - a[j])] = true;
			}
		}
		vector<int> b;
		for(int i = 1; i <= 1000000 && b.size() != n; i++)
		{
			bool ok = true;
			for(int x : b)
			{
				if(ban[abs(x - i)])
				{
					ok = false;
					break;
				}
			}
			if(ok)
			{
				b.push_back(i);
			}
		}
		if(b.size() != n)
		{
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		for(int x : b)
		{
			cout << x << ' ';
		}
		cout << '\n';
	}
}