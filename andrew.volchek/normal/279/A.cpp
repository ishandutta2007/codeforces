#include <iostream>

using namespace std;

int main()
{
	int x, y;
	cin >> x >> y;

	int cnt = 0;

	int curr_x = 0, curr_y = 0;

	int curr_dir = 0;
	int steps_cnt = 1;
	int curr_steps_cnt = 1;;
	int iter = 0;

	while (curr_x != x || curr_y != y)
	{
		if(curr_steps_cnt==0)
		{
			iter++;
			if(!(iter&1))
			{
				steps_cnt++;
			}
			curr_steps_cnt = steps_cnt;
		}

		switch (iter % 4)
		{
		case 0: curr_x++; break;
		case 1: curr_y++; break;
		case 2: curr_x--;	break;
		case 3: curr_y--;break;
		}
		curr_steps_cnt--;

		
	}

	cout << iter;
}