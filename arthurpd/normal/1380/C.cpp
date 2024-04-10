#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int T;
	cin >> T;
	while (T--)
	{
		int n, x;
		cin >> n >> x;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];

		sort(a.rbegin(), a.rend());
		int cur = 0, ans = 0;
		for (int i = 0; i < n; i++)
		{
			cur++;
			if (cur * a[i] >= x)
			{
				ans++;
				cur = 0;
			}
		}

		cout << ans << endl;
	}
}