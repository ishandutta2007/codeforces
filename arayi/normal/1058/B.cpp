#include <iostream>
#include <vector>
using namespace std;


int main()
{
	int n, d, m, a1, b1;
	cin >> n >> d >> m;
	vector <int> c;
	for (int i = 0; i < m; i++)
	{
		cin >> a1 >> b1;
		if (a1 + b1 < d)
			c.push_back(0);
		else if (a1 > n || b1 > n)
			c.push_back(0);
		else if (a1 + b1 > 2 * n - d)
			c.push_back(0);
		else if (((a1 > d) && (b1 < n - d) && (a1 - d > b1) || ((b1 > d) && (a1 < n - d) && (b1 - d > a1))))
			c.push_back(0);
		else
			c.push_back(1);
	}
	for (int i = 0; i < m; i++)
	{
		if (c[i])
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
    return 0;
}