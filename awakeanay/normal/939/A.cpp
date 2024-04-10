#include <iostream>

int main() {
	int n;
	std::cin >> n;
	
	int f[n+1];
	for(int i = 1; i <= n; i++)
		std::cin >> f[i];
	
	bool poss = false;
	for(int i = 1; i <= n; i++) {
		int a = f[i];
		int b = f[a];
		int c = f[b];
		if(c == i)
			poss = true;
	}
	
	
	if(poss)
		std::cout << "YES";
	else 
		std::cout << "NO";
	return 0;
}