#include <iostream>

using namespace std;

int a[105];
int main()
{
	int n, k, maxi = -1, mini = 1000;
	cin >> n;
	cin >> k;
	for(int i = 0; i < n; i ++)
	{
		cin >> a[i];
		maxi = max(a[i], maxi);
		mini = min(a[i], mini);
	}
	if(maxi - mini > k)
	{
		cout << "NO" << endl;
	}
	else
	{
		cout << "YES" << endl;
		for(int i = 0; i < n; i ++)
		{
			for(int j = 1; j <= a[i]; j ++)
			{
				int b = j % k;
				if(b == 0)
				{
					b = k;
				}
				cout << b << " ";
			}
			cout << endl;
		}
	}
	return 0;
}