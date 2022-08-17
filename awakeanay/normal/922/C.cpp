#include <iostream>
#include <unordered_map>

int main()
{
	std::ios::sync_with_stdio(false);
	
	long long n, k;
	std::cin >> n >> k;
	
	std::unordered_map<long long, bool> list;
	
	long long i = 1; bool possible = true;
	while(possible && i <= k)
	{
		if(list[n%i])
			possible = false;
		list[n%i] = true;
		i++;
	}
	
	if(possible)
		std::cout << "Yes";
	else
		std::cout << "No";
	
	return 0;
}