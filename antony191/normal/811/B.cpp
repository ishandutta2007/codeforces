#include <iostream>

using namespace std;

int main()
{
	int n, m, i, j, t, s = 0;
	cin >> n >> m;
	int* a = new int[n];
	int* l = new int[m];
	int* r = new int[m];
	int* x = new int[m];
	int* st = new int[m];
	for (i = 0; i < n; ++i) cin >> a[i];
	for (i = 0; i < m; ++i)
	{
		cin >> l[i] >> r[i] >> x[i];
		if (x[i] < l[i] || x[i] > r[i]) st[i] = 1;
		else
		{
			t = x[i] - l[i];
			for (j = l[i] - 1; j < r[i]; ++j) if (a[j] < a[x[i] - 1]) ++s;
			if (s == t) st[i] = 1;
			else st[i] = 0;
		}
		s = 0;
	}
	for (i = 0; i < m; ++i)
		if (st[i] == 0) cout << "No" << endl;
		else cout << "Yes" << endl;
	return 0;
}