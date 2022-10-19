#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <iterator>
#include <string>
#include <algorithm>
using namespace std;
int a[101], t, n;
int sm(int a)
{
	for (int i = 2; i < 8; i++)
	{
		if (a%i != 1)
		{
			return (a - 1) / i + 1;
		}
	}
}
int main()
{
	//freopen("leash.in", "r", stdin);
	//freopen("leash.out", "w", stdout);
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		a[i] = sm(n);
	}
	for (int i = 0; i < t; i++)
	{
		cout << a[i] << endl;
	}
	return 0;
}