#include <iostream>

using namespace std;

int main()
{
	int m, s;
	cin >> m;
	cin >> s;
	int t = s - 1, n = m;
	if(s == 0 || s > m * 9)
	{
		if(m == 1 && s == 0)
		{
			cout << 0 << " " << 0;
		}
		else
		{
		cout << -1 << " " << -1;
		}
	}
	else
	{
		string a, b;
		if(s >= m)
		{
			for(int i = 9; i > 0; i --)
			{
				int x =  t / i, y = n;
				for(int j = 0; j < min(x, y); j ++)
				{
					n --;
					t -= i;
					char c = '0' + i;
					a += c;
				}
			}
			for(int i = 0; i < n; i ++)
			{
				a += '0';
			}
		}
		else
		{
			for(int i = 9; i > 0; i --)
			{
				int x =  t / i, y = n;
				for(int j = 0; j < min(x, y); j ++)
				{
					n --;
					t -= i;
					char c = '0' + i;
					a += c;
				}
			}
			for(int i = 0; i < n; i ++)
			{
				a += '0';
			}
		}
		a[m - 1] += 1;
		for(int i = a.size() - 1; i >= 0; i --)
		{
			cout << a[i];
		}
		cout << " ";
		for(int i = 9; i >= 1; i --)
		{
			int x = s / i, y = m;
			for(int j = 0; j < min(x, y); j ++)
			{
				m -= 1;
				s = s - i;;
				cout << i;
			}
		}
		for(int i = 0; i < m; i ++)
		{
			cout << 0;
		}
	}
	return 0;
}