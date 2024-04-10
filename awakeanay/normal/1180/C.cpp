#include <iostream>

#define int long long

signed main()
{
	int n, q;
	std::cin >> n;
	std::cin >> q;
	
	int seq[n];
	for(int i = 0; i < n; i++)
		std::cin >> seq[i];
	
	int max[n];
	max[0] = seq[0];
	
	int c = 1;
	int final[n-1];
	for(int i = 1; i < n; i++)
	{
		max[i] = std::max(max[i-1], seq[i]);
		if(seq[i] <= max[i-1])
			final[i-1] = seq[i];
		else
			final[i-1] = max[i-1];
 	}
	
	for(int i = 0; i < q; i++)
	{
		int m;
		std::cin >> m;
		
		if(m <= n-1)
			std::cout << max[m-1] << " " << seq[m] << std::endl;
		else
			std::cout << max[n-1] << " " << final[(m-n)%(n-1)] << std::endl;
	}
	
	return 0;
}