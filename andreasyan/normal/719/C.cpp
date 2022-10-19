#include <iostream>
#include <cstring>
using namespace std;

int n, m, k, res1, res2, e;
char b[200002], a[200002];
int a1, a2;
int main()
{
	int i;
	bool t = false, z = false;
	cin >> n >> k;
	cin >> a;
	for (i = 0; i < n; i++)
	{
		if (a[i] >= '5' && t == true)
		{
			if (a[i - 1] == '.')
			{
				n = i - 1;
				z = true;
				break;
			}
			a[i - 1]++;
			n = i;
			i -= 2;
			k--;
			if (k == 0)
				break;
		}
		if (a[i] == '.')
			t = true;
	}
	t = false;
	int h;
	if (z == true)
	{
		for (i = n - 1; i >= 0; i--)
			if (a[i] != '9')
			{
				t = true;
				h = i;
				break;
			}
////////////////////////////////////////////////////
		if (t == false)
		{
			cout << '1';
			for (i = n - 1; i >= 0; i--)
				cout << '0';
			cout << endl;
//			system("pouse");
			return 0;
		}
////////////////////////////////////////////////////
		for (i = 0; i < h; i++)
		{
			cout << a[i];
		}
		e = a[h] - '0';
		cout << e + 1;
		for (i = h+1; i < n; i++)
			cout << 0;
//		system("pouse");
		return 0;
	}
	for (i = 0; i < n; i++)
	{
		cout << a[i];
	}
//	system("pouse");
	return 0;
}