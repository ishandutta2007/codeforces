#include <stdio.h>

const int gx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
const int gy[8] = {0, -1, 1, 0, -1, 1, -1, 1};

int x[4];
int y[4];

bool KOed[8][8];
bool KOed0[8][8], KOed1[8][8];

inline bool inside (int x, int y)
{
	return x >= 0 && x < 8 && y >= 0 && y < 8;
}

int main ()
{
	for (int i = 0; i < 4; i ++)
	{
		char xx;
		do scanf ("%c", &xx); while (xx <= ' ');

		x[i] = xx - 'a';
		scanf ("%d", y + i);
		y[i] --;
	}

	for (int i = 0; i < 8; i ++)
		for (int j = 0; j < 8; j ++)
			KOed[i][j] = false;
	for (int i = 0; i < 8; i ++)
		for (int j = 0; j < 8; j ++)
			KOed0[i][j] = false;
	for (int i = 0; i < 8; i ++)
		for (int j = 0; j < 8; j ++)
			KOed1[i][j] = false;

	for (int i = 0; i < 4; i ++)
		for (int j = 0; j < 8; j ++)
		{
			if (x[0] + gx[i] * j == x[2] && y[0] + gy[i] * j == y[2])
				break;
			if (inside(x[0] + gx[i] * j, y[0] + gy[i] * j))
				KOed[x[0] + gx[i] * j][y[0] + gy[i] * j] = true;
			if (inside(x[0] + gx[i] * j, y[0] + gy[i] * j))
				KOed1[x[0] + gx[i] * j][y[0] + gy[i] * j] = true;
		}
	for (int i = 0; i < 4; i ++)
		for (int j = 0; j < 8; j ++)
		{
			if (x[1] + gx[i] * j == x[2] && y[1] + gy[i] * j == y[2])
				break;
			if (inside(x[1] + gx[i] * j, y[1] + gy[i] * j))
				KOed[x[1] + gx[i] * j][y[1] + gy[i] * j] = true;
			if (inside(x[1] + gx[i] * j, y[1] + gy[i] * j))
				KOed0[x[1] + gx[i] * j][y[1] + gy[i] * j] = true;
		}
	for (int i = 0; i < 8; i ++)
		for (int j = 0; j <= 1; j ++)
			if (inside(x[2] + gx[i] * j, y[2] + gy[i] * j))
			{
				KOed[x[2] + gx[i] * j][y[2] + gy[i] * j] = true;
				KOed0[x[2] + gx[i] * j][y[2] + gy[i] * j] = true;
				KOed1[x[2] + gx[i] * j][y[2] + gy[i] * j] = true;
			}
	
	bool check = KOed[x[3]][y[3]], canmove = false;
	for (int i = 0; i < 8; i ++)
	{
		if (inside(x[3] + gx[i], y[3] + gy[i]) && !KOed[x[3] + gx[i]][y[3] + gy[i]])
			canmove = true;
		if (inside(x[3] + gx[i], y[3] + gy[i]) && (x[3] + gx[i] == x[0] && y[3] + gy[i] == y[0]) && !KOed0[x[3] + gx[i]][y[3] + gy[i]])
			canmove = true;
		if (inside(x[3] + gx[i], y[3] + gy[i]) && (x[3] + gx[i] == x[1] && y[3] + gy[i] == y[1]) && !KOed1[x[3] + gx[i]][y[3] + gy[i]])
			canmove = true;
	}
	
	if (check && !canmove)
		printf ("CHECKMATE\n");
	else
		printf ("OTHER\n");

	return 0;
}