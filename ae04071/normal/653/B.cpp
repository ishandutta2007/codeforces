#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

int n, q;
std::string* a;
std::string* b;

int sum[6];

int dy_arr[5][6];

int Process(char ch, int num)
{
	if (num == n-1)
	{
		dy_arr[num][ch - 'a'] = 1;
		return dy_arr[num][ch - 'a'];
	}
	if (dy_arr[num][ch - 'a'] != -1) return dy_arr[num][ch - 'a'];

	dy_arr[num][ch - 'a'] = 0;

	for (int i = 0; i < q; i++)
	{
		if (b[i][0] == ch)
		{
			dy_arr[num][ch - 'a'] += Process(a[i][0], num + 1);
		}
	}

	return dy_arr[num][ch - 'a'];
}

int main()
{
	scanf("%d %d", &n, &q);

	a = new std::string[q];
	b = new std::string[q];

	for (int i = 0; i < q; i++)
	{
		std::cin >> a[i] >> b[i];
		sum[b[i][0] - 'a'] += 1;
	}
	
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			dy_arr[i][j] = -1;
		}
	}

	Process('a', 0);
	printf("%d\n", dy_arr[0][0]);

	return 0;
}