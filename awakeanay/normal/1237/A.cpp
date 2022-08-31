#include <iostream>

int main() {
	int n;
	std::cin >> n;

	int p = 0, m = 0;
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;

		if(abs(x)%2) {
			if(x > 0) {
				p++;
				if(p%2)
					std::cout << x/2;
				else
					std::cout << x/2+1;
			}
			else {
				m++;
				if(m%2)
					std::cout << x/2;
				else
					std::cout << x/2-1;
			}


		}
		else {
			std::cout << x/2;
		}

		std::cout << std::endl;
	}

	return 0;
}