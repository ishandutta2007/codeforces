#include <iostream>

using namespace std;

int l[1000005];
int main()
{
	ios::sync_with_stdio(false);
	int n, q, s = 0, x = 0, y = 0;
	cin >> n;
	cin >> q;
	for(int i = 0; i < q; i ++)
	{
		int a;
		cin >> a;
		if(a == 1)
		{
			int b;
			cin >> b;
			s += b;
			s = s% n;
		}
		else
		{
			if((s + x + y) % 2 == 0)
			{
				x ++;
			}
			else
			{
				y ++;
			}
		}
	}
	for(int i = 1; i <= n; i ++)
	{
		int a = i;
		a += s;
		if(i % 2 == 0)
		{
			a -= x;
			a += y;
		}
		else
		{
			a += x;
			a -= y;
		}
		a = a % n;
		if(a <= 0)
		{
			a += n;
		}
		l[a] = i;
	}
	for(int i = 1; i <= n; i ++)
	{
		cout << l[i] << " ";
	}
	return 0;
}