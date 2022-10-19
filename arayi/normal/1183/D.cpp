#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
const int N = 2 * 1000000;
stack <long long int > t;
long long int n, x, m, l, r, y;
long long int   pat;
long long int a[N], tex[N];

int main()
{
	cin >> m;
	for (int o = 1; o <= m; o++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];

		}
		sort(a, a + n);
		y = a[n - 1];
		for (int i = 1; i <= n; i++)
		{
			//cout << 5 << endl;
			x = 1;
			while (i < n && a[i] == a[i - 1])
			{
				i++;
				x++;
			}
			if (tex[x] != o)
			{
				pat += x;
				tex[x] = o;
				
			}
			
			else {
				while (x > 0 && tex[x] == o)
				{
					x--;
				}
			//	cout << x << endl;
				tex[x] = o;
				pat += x;
			}
			
		}
		cout << pat << endl;
		pat = 0;
		for (int i = 0; i <= n; i++)
		{
			tex[i] = 0;
		}
	}
	
}