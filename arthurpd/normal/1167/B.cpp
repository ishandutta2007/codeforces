#include <bits/stdc++.h>
using namespace std;

int a[6] = {4, 8, 15, 16, 23, 42};


int main(void)
{
	// for (int i = 0; i < 6; i++)
	// 	for (int j = i + 1; j < 6; j++)
	// 		cout << a[i] * a[j] << endl;

	int ans[7];
	int x;
	for (int i = 0; i < 4; i++)
	{
		printf("? %d %d\n", i + 1, i + 2);
		fflush(stdout);
		scanf("%d", &x);
		for (int k = 0; k < 6; k++)
			for (int j = k + 1; j < 6; j++)
				if (x == a[k] * a[j])
				{
					if (ans[i] == a[j] || ans[i] == a[k])
						swap(ans[i], ans[i+1]);
					
					if (ans[i + 1] == a[j])
						ans[i + 2] = a[k];
					else
					{
						ans[i + 1] = a[k];
						ans[i + 2] = a[j];
					}
				}
	}
	ans[6] = 108 - ans[5] - ans[4] - ans[3] - ans[2] - ans[1];
	printf("! %d %d %d %d %d %d\n", ans[1], ans[2], ans[3], ans[4], ans[5], ans[6]);
}