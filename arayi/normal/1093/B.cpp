#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <iterator>
#include <string>
#include <algorithm>
using namespace std;
string a[101], n;
int t;
bool polindr(string a)
{
	string b = a;
	reverse(b.begin(), b.end());
	if (a == b)
		return 1;
	return 0;
}
string sm(string a)
{
	for (int i = 1; i < a.length(); i++)
	{
		if (a[i] != a[0])
		{
			int ss = a[i] - a[0];
			a[i] -= ss;
			a[0] += ss;
			return a;
		}
	}
	return "-1";
}
int main()
{
	//freopen("leash.in", "r", stdin);
	//freopen("leash.out", "w", stdout);
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		if (n.length() == 1)
			a[i] = "-1";
		else if (!polindr(n))
			a[i] = n;
		else {
			a[i] = sm(n);
		}
	}
	for (int i = 0; i < t; i++)
	{
		cout << a[i] << endl;
	}
	return 0;
}