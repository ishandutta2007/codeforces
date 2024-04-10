#include <iostream>

using namespace std;

int a[100005];
int b[100005];
char c[100005];
int d[100005];
bool e[100005];
int main()
{
	int n, m, x = 0, y = 0, f = 0;
	cin >> n;
	cin >> m;
	for(int i = 1; i <= n; i ++)
	{
		cin >> c[i];
		if(c[i] == '+')
		{
			x ++;
			cin >> d[i];
			a[d[i]] ++;
		}
		else
		{
			y ++;
			cin >> d[i];
			b[d[i]] ++;
		}
	}
	for(int i = 1; i <= n; i ++)
	{
		if(y + a[i] - b[i] == m)
		{
			e[i] = true;
			f ++;
		}
		else
		{
			e[i] = false;
		}
	}
	for(int i = 1; i <= n; i ++)
	{
		if(c[i] == '+')
		{
			if(e[d[i]] == true)
			{
				if(f == 1)
				{
					cout << "Truth";
				}
				else
				{
					cout << "Not defined";
				}
			}
			else
			{
				cout << "Lie";
			}
		}
		else
		{
			if(e[d[i]] == true)
			{
				if(f == 1)
				{
					cout << "Lie";
				}
				else
				{
					cout << "Not defined";
				}
			}
			else
			{
				cout << "Truth";
			}
		}
		cout << endl;
	}
	return 0;
}