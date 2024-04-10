#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string a;
	cin >> a;
	int q = 0;
	for (int i = 0; i < n; i++)
	{
		if (((i - q) % 2 == 0) && (a[i - q] == a[(i - q) + 1]))
		{
			a.erase((i - q), 1);
			q++;
		}

	}
	if (a.length() % 2 == 0)
		{
			cout << q << endl;
			cout << a;
		}
	else if (a.length()	 % 2 == 1)
		{
			if (a.length() > 1)
			{
				a.erase((a.length() - 1), 1);
				q++;
				cout << q << endl;
				cout << a;

			}
			else if (a.length() == 1)
			{
				q++;
				cout << q;
			}

		}

}