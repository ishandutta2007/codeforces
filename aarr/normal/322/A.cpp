#include <iostream>

using namespace std;

int main()
{
	int n, m;
	cin >> n;
	cin >> m;
	cout << m + n - 1 << endl;
	for(int i = 1; i <= n; i ++)
	{
		cout << i << " " << 1 << endl;
	}
	for(int i = 2; i <= m; i ++)
	{
		cout << 1 << " " << i << endl;
	}
	return 0;
}