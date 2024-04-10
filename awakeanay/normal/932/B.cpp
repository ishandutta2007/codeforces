#include <iostream>
#include <vector>
#include <unordered_map>

#define INF 1000000

int calc(long num)
{
	if(num < 10)
		return num;
	long rec = 1;
	while(num != 0)
	{
		if(num%10 != 0)
			rec *= num%10;
		num/=10;
	}
	return calc(rec);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	
	std::unordered_map<long, std::vector<long>> list;
	for(long i = 1; i <= INF; i++)
	{
		for(int j = 0; j < 9; j++)
			list[i].push_back((i > 1) ? list[i-1][j] : 0);
		list[i][calc(i)-1]++;
	}
	
	long Q;
	std::cin >> Q;
	
	for(long i = 0; i < Q; i++)
	{
		long l, r;
		int k;
		std::cin >> l >> r >> k;
		
		std::cout << list[r][k-1] - ((l > 1) ? list[l-1][k-1] : 0) << "\n";
	}
	
	return 0;
}