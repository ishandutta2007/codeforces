#include <iostream>
using namespace std;

int my_max(int x,int y)
{
	return x > y ? x : y;
}

int main()
{
	char p[100][10000] = { 0 };
	int ppoint[100][10];
	int n[100];
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n[i];
		for (int j = 0; j < n[i]; j++)
		{
			int h;
			cin >> h;
			ppoint[i][j] = h;
			p[i][h]++;
		}
	}
	for (int i = 0; i < t; i++)
	{
		int ans = 0;
		for (int j = 0; j < 10000; j++)
			ans += my_max(p[i][j]-1,0);
		cout << ans << endl;
		printf("%0.4i\n", ppoint[i][0]);
		for (int j = 1; j < n[i]; j++)
		{
			bool e=0;
			for (int x = 0; x < n[i]; x++)
			{
				if (x != j)
				{
					if (ppoint[i][x] == ppoint[i][j])
					{
						e = 1;
						break;
					}
				}
			}
			if (!e)
				printf("%0.4i\n", ppoint[i][j]);
			else
			{
				int d = -1;
				back:
				d++;
				for (int x = 0; x < n[i]; x++)
				{
					if (x != j)
					{
						if ((ppoint[i][j] / 10) * 10 + d == ppoint[i][x])
						{
							goto back;
						}
					}
				}
				ppoint[i][j] = (ppoint[i][j] / 10) * 10 + d;
				printf("%0.4i\n", ppoint[i][j]);
			}
		}
	}
}