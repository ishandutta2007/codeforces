#include <iostream>

int main()
{
	long n, t;
	std::cin >> n >> t;
	
	long min = 10000000;
	long ans = 0;
	
	for(int i = 0; i < n; i++)
	{
		long a, b;
		std::cin >> a >> b;
		
		long upd = a;
		
		while(upd < t)
			upd += 100*b;
		
		while(upd - b >= t && upd - b >= a)
			upd -= b;
		
		if(upd < min)
		{
			min = upd;
			ans = i+1;
		}
	}
	
	std::cout << ans;
	
	return 0;
}