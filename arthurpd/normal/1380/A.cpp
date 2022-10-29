#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector<int> p(n);
		for (int i = 0; i < n; i++)
			cin >> p[i];

		vector<int> pref_min(n, p[0]);
		vector<int> suf_min(n, p[n - 1]);

		for (int i = 1; i < n; i++)
			pref_min[i] = min(p[i], pref_min[i - 1]);

		for (int i = n - 2; i >= 0; i--)
			suf_min[i] = min(p[i], suf_min[i + 1]);

		bool ok = false;
		for (int i = 1; i < n - 1; i++)
		{
			if (pref_min[i] < p[i] && suf_min[i] < p[i])
			{
				ok = true;
				cout << "YES" << endl;
				for (int j = 0; j < i; j++)
					if (p[j] < p[i])
					{
						cout << (j + 1);
						break;
					}

				cout << " " << (i + 1) << " ";
				for (int j = i + 1; j < n; j++)
					if (p[j] < p[i])
					{
						cout << (j + 1) << endl;
						break;
					}
				break;
			}
		}

		if (!ok)
			cout << "NO" << endl;
	}
}