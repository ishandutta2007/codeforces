
#include <iostream>
#include <algorithm>
#include <cstring>

int main() {
	int n, m;
	std::cin >> n >> m;
	std::string full = "";
	for(int i = 0; i < m; ++i)
		full+= "#";
	std::string left = "#";
	std::string right = "";
	for(int i = 1; i < m; ++i) {
		left += ".";
		right += ".";
	}
	right += "#";
	for(int i = 0; i < n; ++i) {
		if(!(i&1))
			std::cout <<full << "\n";
		else
			if(i%4 == 1)
				std::cout <<right<<"\n";
			else std::cout <<left<<"\n";
	}
	return 0;
}