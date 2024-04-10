#include <iostream>

struct coord
{
	int x, y;
};

int box[2][2];
int xNum[1000];
int yNum[1000];

int main()
{
	coord k;
	coord rs[666];
	
	std::cin >> k.x >> k.y;
	
	for(int i = 0; i < 666; i++)
	{
		std::cin >> rs[i].x >> rs[i].y;
		xNum[rs[i].x]++;
		yNum[rs[i].y]++;
		if(rs[i].x > k.x && rs[i].y > k.y)
			box[1][1]++;
		else if(rs[i].x < k.x && rs[i].y < k.y)
			box[0][0]++;
		else if(rs[i].x < k.x)
			box[0][1]++;
		else
			box[1][0]++;
	}
	
	int min = 667;
	coord dir;
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			if(box[i][j] <= min)
			{
				min = box[i][j];
				dir.x = 1-2*i;
				dir.y = 1-2*j;
			}
		}
	}

	while(true)
	{
		if(xNum[k.x + dir.x] > 0)
			std::cout << k.x + dir.x << " " << k.y << std::endl;
		else if(yNum[k.y + dir.y] > 0)
			std::cout << k.x << " " << k.y + dir.y << std::endl;
		else
		{
			k.x = k.x + dir.x;
			k.y = k.y + dir.y;
			if(k.x > 999) k.x = 999;
			if(k.x < 1) k.x = 1;
			if(k.y > 999) k.y = 999;
			if(k.y < 1) k.y = 1;
			std::cout << k.x  << " " << k.y << std::endl;
		}
		
		int a, b, c;
		std::cin >> a >> b >> c;
		if(a == -1)
			break;
		else
		{
			a--;
			xNum[rs[a].x]--;
			yNum[rs[a].y]--;
			xNum[b]++;
			yNum[c]++;
			rs[a].x = b;
			rs[a].y = c;
		}
	}
	
	return 0;
}