#include <iostream>

int main() {
	int n;
	std::cin >> n;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			int x = j*n;
			if(j%2)
				x += i;
			else
				x += n-1-i;
			std::cout << x+1 << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}