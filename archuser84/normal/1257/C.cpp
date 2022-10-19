#include <iostream>
#define Loop int loop = 0; loop < t; loop++
#define LoopN int i = 0; i < n; i++
using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}
int min(int a, int b)
{
	return a < b ? a : b;
}

int main()
{
	int t;
	int ans[1000];
	cin >> t;
	for (Loop)
	{
		ans[loop] = 300000;
		int n;
		cin >> n;
		int last[200001];
		bool exist[200001] = { 0 };
		for (LoopN)
		{
			int h;
			cin >> h;
			if (exist[h])
			{
				int x = i - last[h] + 1;
				if (x < ans[loop])
					ans[loop] = x;
			}
			last[h] = i;
			exist[h] = true;
		}
		if (ans[loop] == 300000)
			ans[loop] = -1;
	}
	for (Loop)
	{
		cout << ans[loop] << '\n';
	}
}