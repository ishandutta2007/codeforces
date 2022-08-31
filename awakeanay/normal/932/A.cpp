#include <iostream>
#include <string>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	
	std::string A;
	std::cin >> A;
	
	std::cout << A;
	for(int i = 0; i < A.size(); i++)
		std::cout << A.at(A.size()-1-i);
	
	return 0;
}