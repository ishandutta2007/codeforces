#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <int> a(300000, n);
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		a[x] = i;
	}
	int x=  -1;
	for (int i = 0; i < 300000; i++)
	{
		if (x == -1 || a[i] < a[x])
		{
			x = i;
		}
	}
	cout << x << '\n';
}