#include <stdio.h>

int k, n, m, x, y;
char data[10][10][10];

int dfsfill (int x, int y, int z)
{
	data[x][y][z] = '*';
	int re = 1;

	if (x - 1 >= 0 && data[x - 1][y][z] == '.')
		re += dfsfill(x - 1, y, z);
	if (y - 1 >= 0 && data[x][y - 1][z] == '.')
		re += dfsfill(x, y - 1, z);
	if (z - 1 >= 0 && data[x][y][z - 1] == '.')
		re += dfsfill(x, y, z - 1);
	if (x + 1 < k && data[x + 1][y][z] == '.')
		re += dfsfill(x + 1, y, z);
	if (y + 1 < n && data[x][y + 1][z] == '.')
		re += dfsfill(x, y + 1, z);
	if (z + 1 < m && data[x][y][z + 1] == '.')
		re += dfsfill(x, y, z + 1);
	
	return re;
}

int main ()
{
	scanf ("%d%d%d", &k, &n, &m);

	for (int i = 0; i < k; i ++)
		for (int j = 0; j < n; j ++)
			for (int l = 0; l < m; l ++)
			{
				char ch;

				do scanf ("%c", &ch);
					while (ch <= ' ');

				data[i][j][l] = ch;
			}
	
	scanf ("%d%d", &x, &y);
	x --;
	y --;

	printf ("%d\n", dfsfill(0, x, y));

	return 0;
}