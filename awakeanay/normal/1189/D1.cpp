#include <iostream>

int main()
{
	int n;
	std::cin >> n;

	int deg[n];
	for(int i = 0; i < n; i++)
		deg[i] = 0;

	for(int i = 1; i < n; i++)
	{
		int a, b;
		std::cin >> a >> b;
		a--; b--;
		deg[a]++;
		deg[b]++;
	}

	bool poss = true;
	for(int i = 0; i < n; i++)
		if(deg[i] == 2)
			poss = false;

	if(poss)
		std::cout << "YES";
	else
		std::cout << "NO";

	std::cout << std::endl;
}