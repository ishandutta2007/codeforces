
#include <iostream>
#include <algorithm>
#include <cstring>

int main() {
	int n;
	std::cin >> n;
	
	int m;
	std::cin >> m;
	bool prev = (m == 1);
	int count = 1;
	for(; n > 1; --n) {
		std::cin >> m;
		bool current = (m == 1);
		if(current != prev) {
			prev = current;
			++count;
		}
	}
	std::cout << count;
	
	return 0;
}