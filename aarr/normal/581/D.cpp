#include <iostream>

using namespace std;

int a[5];
int b[5];
int c[5];
int main()
{
	int x = -1, y = -1, z = -1, d = -1;
	cin >> a[0];
	cin >> a[1];
	cin >> b[0];
	cin >> b[1];
	cin >> c[0];
	cin >> c[1];
	for(int i = 0; i < 2; i ++)
	{
		for(int j = 0; j < 2; j ++)
		{
			for(int k = 0; k < 2; k ++)
			{
				if(a[i] == b[j] && a[i] == c[k] && a[i] == a[(i + 1) % 2] + b[(j + 1) % 2] + c[(k + 1) % 2])
				{
					x = i;
					y = j;
					z = k;
					d = 0;
				}
				if(a[i] == b[j] + c[k] && a[i] == a[(i + 1) % 2] + b[(j + 1) % 2] && b[(j + 1) % 2] == c[(k + 1) % 2])
				{
					x = i;
					y = j;
					z = k;
					d = 1;
				}
				if(b[j] == a[i] + c[k] && b[j] == a[(i + 1) % 2] + b[(j + 1) % 2] && a[(i + 1) % 2] == c[(k + 1) % 2])
				{
					x = i;
					y = j;
					z = k;
					d = 2;
				}
				if(c[k] == b[j] + a[i] && c[k] == c[(k + 1) % 2] + b[(j + 1) % 2] && b[(j + 1) % 2] == a[(i + 1) % 2])
				{
					x = i;
					y = j;
					z = k;
					d = 3;
				}
			}
		}
	}
	if(d < 0)
	{
		cout << -1;
	}
	if(d == 0)
	{
		cout << a[x] << endl;
		for(int i = 0; i < a[(x + 1) % 2]; i ++)
		{
			for(int j = 0; j < a[x]; j ++)
			{
				cout << 'A';
			}
			cout << endl;
		}
		for(int i = 0; i < b[(y + 1) % 2]; i ++)
		{
			for(int j = 0; j < b[y]; j ++)
			{
				cout << 'B';
			}
			cout << endl;
		}
		for(int i = 0; i < c[(z + 1) % 2]; i ++)
		{
			for(int j = 0; j < c[z]; j ++)
			{
				cout << 'C';
			}
			cout << endl;
		}
	}
	if(d == 1)
	{
		cout << a[x] << endl;
		for(int i = 0; i < a[(x + 1) % 2]; i ++)
		{
			for(int j = 0; j < a[x]; j ++)
			{
				cout << 'A';
			}
			cout << endl;
		}
		for(int i = 0; i < b[(y + 1) % 2]; i ++)
		{
			for(int j = 0; j < b[y]; j ++)
			{
				cout << 'B';
			}
			for(int j = 0; j < c[z]; j ++)
			{
				cout << 'C';
			}
			cout << endl;
		}
	}
	if(d == 2)
	{
		cout << b[y] << endl;
		for(int i = 0; i < b[(y + 1) % 2]; i ++)
		{
			for(int j = 0; j < b[y]; j ++)
			{
				cout << 'B';
			}
			cout << endl;
		}
		for(int i = 0; i < a[(x + 1) % 2]; i ++)
		{
			for(int j = 0; j < a[x]; j ++)
			{
				cout << 'A';
			}
			for(int j = 0; j < c[z]; j ++)
			{
				cout << 'C';
			}
			cout << endl;
		}
	}
	if(d == 3)
	{
		cout << c[z] << endl;
		for(int i = 0; i < c[(z + 1) % 2]; i ++)
		{
			for(int j = 0; j < c[z]; j ++)
			{
				cout << 'C';
			}
			cout << endl;
		}
		for(int i = 0; i < b[(y + 1) % 2]; i ++)
		{
			for(int j = 0; j < b[y]; j ++)
			{
				cout << 'B';
			}
			for(int j = 0; j < a[x]; j ++)
			{
				cout << 'A';
			}
			cout << endl;
		}
	}
	return 0;
}