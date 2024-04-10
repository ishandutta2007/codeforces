#include <iostream>

#define INF 10000000

int main() 
{
	int N;
	std::cin >> N;
	
	long mx, my, ma, mb;
	mx = my = INF;
	ma = mb = -INF;
	
	for(int i = 0; i < N; i++)
	{
		long x, y;
		std::cin >> x >> y;
		mx = std::min(x, mx);
		my = std::min(y, my);
	}
	
	for(int i = 0; i < N; i++)
	{
		long a, b;
		std::cin >> a >> b;
		ma = std::max(a, ma);
		mb = std::max(b, mb);
	}
	
	std::cout << mx + ma << " " << my + mb;
	
	return 0;
}