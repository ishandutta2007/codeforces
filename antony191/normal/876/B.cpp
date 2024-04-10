#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n, k, m; 
	cin >> n >> k >> m;
	int* a = new int[n];
	int* b = new int[m];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) b[i] = 0;
	for (int i = 0; i < n; i++)
	{
		b[a[i] % m]++;
	}
	for (int i = 0; i < m; i++)
	{
		if (b[i] >= k)
		{
			cout << "Yes" << endl;
			int tmp = 0;
			for (int j = 0; j < n; j++)
			{
				if (a[j] % m == i && tmp < k)
				{
					cout << a[j] << " ";
					tmp++;
				}
			}
			return 0;
		}
	}
	cout << "No";
	return 0;
}