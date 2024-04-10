#include <iostream>

using namespace std;

int main()
{
	int n; cin >> n;
	int* a = new int[n];
	int i, s = 0, b = 0;
	int* t1 = new int[n];
	int* t2 = new int[n];
	for (i = 0; i < n; ++i)
	{
		t1[i] = 0;
		t2[i] = 0;
	}
	for (i = 0; i < n; ++i)
	{
		cin >> a[i];
		if (s == 0 && a[i] == 0) ++b;
		else if (s == 0 && a[i] == 1)
		{
			++s; t1[s - 1] = 1;
		}
		else if (s > 0 && a[i] == 0)
				if (a[i - 1] == 1) t2[s - 1] = 1;
				else ++t2[s - 1];
		else if (a[i - 1] == 1) ++t1[s - 1];
		else
		{
			++s;
			t1[s - 1] = 1;
		}
	}
	int k1 = 0, max, k2 = 0;
	for (i = 0; i < s; ++i) k1 += t1[i];
	max = k1;
	for (i = 0; i < s; ++i)
	{
		k1 -= t1[i];
		k2 += t2[i];
		if (max < k1 + k2) max = k1 + k2;
	}
	cout << max + b;
}