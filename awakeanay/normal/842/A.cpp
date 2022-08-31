#include <iostream>
using namespace std;

int main() {
	double a, b, x, y, k;
	std::cin >> a >> b >> x >> y >> k;
	
	bool poss = false;
	for(int i = x; i <= y && !poss; i++) {
		if(i*k >= a && i*k <= b)
			poss = true;
	}
	
	if(poss)
		std::cout << "YES";
	else
		std::cout << "NO";
	return 0;
}