#include <iostream>

int main()
{
	int n, m;
	std::cin >> n >> m;

	long long a[n][m], b[n][m];

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			std::cin >> a[i][j];

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			std::cin >> b[i][j];

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(a[i][j] > b[i][j])
				std::swap(a[i][j], b[i][j]);

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(i && (a[i][j] <= a[i-1][j]))
				std::swap(a[i][j], b[i][j]);
			else if(j && (a[i][j] <= a[i][j-1]))
				std::swap(a[i][j], b[i][j]);
		}
	}

	bool poss = true;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(i && (a[i][j] <= a[i-1][j]))
				poss = false;
			else if(j && (a[i][j] <= a[i][j-1]))
				poss = false;
			if(i && (b[i][j] <= b[i-1][j]))
				poss = false;
			else if(j && (b[i][j] <= b[i][j-1]))
				poss = false;
		}
	}

	if(poss)
		std::cout << "Possible";
	else
		std::cout << "Impossible";
}