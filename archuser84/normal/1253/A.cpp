#include <iostream>
#define Loop int loop = 0; loop < t; ++loop
#define LoopN int i = 0; i < n; ++i
#define LoopM int j = 0; j < m; ++j
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (Loop)
	{
		int a[100000];
		int n;
		cin >> n;
		for (LoopN)
			cin >> a[i];
		int k = 0;
		bool end = 0;
		for (LoopN)
		{
			int b;
			cin >> b;
			if (k != -1)
			{
				if (b == a[i] && k != 0)
					end = 1;
				if (b < a[i])
					k = -1;
				if (b > a[i])
				{
					if (k == 0)
						k = b - a[i];
					else if (k != b - a[i] || end)
						k = -1;
				}
			}
		}
		if (k != -1)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}