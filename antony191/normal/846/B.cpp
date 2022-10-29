#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int proverka(int n, int k, int m);
vector<int> a;
int main()
{
	int n, k, m, i, s = 0, u;
	cin >> n >> k >> m;
	for (i = 0; i < k; ++i)
	{
		cin >> u;
		a.push_back(u);
		s += a[i];
	}
	sort(a.begin(), a.end());
	//for (i = 0; i < k; ++i) cout << a[i];
	//cout << endl;
	int b = m / s, max = 0, t;
	if (b > n) b = n;
	for (i = 0; i <= b; ++i)
	{
		t = (k + 1) * i + proverka(n - i, k, m - i * s);
		if (t > max) max = t;
	}
	cout << max;
	return 0;
}

int proverka(int n, int k, int m)
{
	int t = 0, i = 0, s;
	while (m > 0 && i < k)
	{
		s = m / a[i];
		if (s < n)
		{
			t += s;
			break;
		}
		else
		{
			t += n;
			m -= n * a[i];
		}
		++i;
	}
	return t;
}