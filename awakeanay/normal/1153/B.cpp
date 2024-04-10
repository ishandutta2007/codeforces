#include <iostream>

int main()
{
	int n, m, h;
	std::cin >> n >> m >> h;
	
	int front[m], left[n];
	for(int i = 0; i < m; i++)
		std::cin >> front[i];
		
	for(int i = 0; i < n; i++)
		std::cin >> left[i];
	
	int mat[n][m];
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			bool val;
			std::cin >> val;
			if(val)
				mat[i][j] = std::min(front[j], left[i]);
			else
				mat[i][j] = 0;
		}
	}
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
			std::cout << mat[i][j] << " ";
		std::cout << std::endl;
	}
	
	return 0;
}