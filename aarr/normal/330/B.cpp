#include <iostream>

using namespace std;

bool b[1005];
int main()
{
	int n, m, v;
	cin >> n;
	cin >> m;
	for(int i = 0; i < m; i ++)
	{
		int x, y;
		cin >> x;
		cin >> y;
		b[x] = true;
		b[y] = true;
	}
	for(int i = 1; i <= n; i ++)
	{
		if(b[i] == false)
		{
			v = i;
			break;
		}
	}
	cout << n - 1 << endl;
	for(int i = 1; i <= n; i ++)
	{
		if(v != i)
		{
			cout << v << " " << i << endl;
		}
	}
	return 0;
}