#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector <int> a(n);
	map <int, int> ret;
	for (int i = 0; i < n; i++)
	{
		 cin >> a[i];
	}
	ret[1] = 0;
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++)
	{
		 ret[a[i]]++;
		 if (i != 0 && a[i] != a[i - 1])
		 {
			  ret[a[i]] += ret[a[i - 1]];
		 }
	}
	for (auto c : ret)
	{
		if (c.second == k)
		{
			 cout << c.first << '\n';
			 return 0;
		}
	}
	cout << -1 << '\n';
}