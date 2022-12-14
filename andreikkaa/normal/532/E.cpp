#include <iostream>
#include <vector>
#include <string>

using namespace std;

void z_func(string s, vector<int>& z)
{
	int n = s.length();
	for (int i = 1, l = 0, r = 0; i < n; i++)
	{
		if (i <= r)
			z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			z[i]++;
		if (i + z[i] - 1 > r)
		{
			l = i;
			r = i + z[i] - 1;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	int beg = 0, en = n;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == b[i])
			beg++;
		else
			break;
	}
	for (int i = n - 1; i > -1; i--)
	{
		if (a[i] == b[i])
			en--;
		else
			break;
	}
	string c, d;
	int cnt = 0;
	for (int i = beg; i < en; i++)
	{
		c += a[i];
		d += b[i];
	}
	if (c.length() == 1)
	{
		cout << 2 << endl;
		return 0;
	}
	string e = c + "&" + d;
	int l = c.length();
	vector<int> z(2 * l + 1);
	z_func(e, z);
	if (z[l + 2] + l + 2 == e.length())
	{
		cnt++;
	}
	e = "";
	e = d + "&" + c;
	vector<int> z1(2 * l + 1);
	z_func(e, z1);
	if (z1[l + 2] + l + 2 == e.length())
	{
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}