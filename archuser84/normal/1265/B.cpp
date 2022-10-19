#include <iostream>
#define Loop int loop = 0; loop < t; ++loop
#define LoopN int i = 0; i < n; ++i
#define LoopM int j = 0; j < m; ++j
using namespace std;

int main()
{
	int t;
	int n[1000];
	bool ans[1000][200000];
	cin >> t;
	for (Loop)
	{
		cin >> n[loop];
		int p[200000];
		int ppoint[200000];
		bool b[200000] = { 0 };
		for (int i = 0; i < n[loop]; i++)
		{
			cin >> p[i];
			ppoint[p[i] - 1] = i;
		}
		int x = 0;
		for (int i = 0; i < n[loop]; i++)
		{
			int j = ppoint[i];
			b[j] = 1;
			++x;
			if (j < n[loop] - 1)
				if (b[j + 1])
					--x;
			if (j > 0)
				if (b[j - 1])
					--x;
			ans[loop][i] = (x == 1);
		}
	}
	for (Loop)
	{
		for (int i = 0; i < n[loop]; ++i)
			cout << ans[loop][i];
		cout << '\n';
	}
}