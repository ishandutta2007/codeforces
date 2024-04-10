#include <iostream>
using namespace std;

long long a[100002], n, maxi;
long long b[400002], c[100002];
long long res;
int find(int tl, int tr, int poz, int i)
{
	if (tl == tr)
		return poz;
	int m = (tl + tr) / 2;
	if (i <= m)
		return find(tl, m, poz * 2, i);
	return find(m + 1, tr, poz * 2 + 1, i);
}

void ubdate(int i, int x)
{
	int poz = find(1, n, 1, i);
	while (poz)
	{
		if (x >= a[b[poz]] || a[b[poz]] == 0)
			b[poz] = i;
		poz = poz / 2;
	}
}
int maximum(int tl, int tr, int l, int r, int poz)
{
	int m = (tl + tr) / 2;
	if (tl == l && tr == r)
		return b[poz];
	if (r <= m)
		return maximum(tl, m, l, r, poz * 2);
	if (l > m)
		return maximum(m + 1, tr, l, r, poz * 2 + 1);
	int a1 = maximum(tl, m, l, m, poz * 2);
	int a2 = maximum(m + 1, tr, m + 1, r, poz * 2 + 1);
	return a[a1] > a[a2] ? a1 : a2;
}

int main()
{
	int i, j;
	cin >> n;
	for (i = 1; i < n; i++)
		cin >> a[i];
	c[n - 1] = 1;
	ubdate(n - 1, a[n - 1]);
	for (i = n - 2; i >= 1; i--)
	{
		maxi = maximum(1, n, i + 1, a[i], 1);
//		cerr << minu << endl;
		if (a[i] == n)
		{
			c[i] = (a[i] - i);
			res += c[i];
			ubdate(i, a[i]);
			continue;
		}
		c[i] = (a[i] - i) + c[maxi] - (a[i] - maxi) + n - a[i];
		res += c[i];
		ubdate(i, a[i]);
	}
	cout << res + 1 << endl;
//	system("pause");
	return 0;
}