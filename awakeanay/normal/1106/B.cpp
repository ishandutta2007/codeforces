#include <iostream>
#include <set>

int main()
{
	int N, M;
	std::cin >> N >> M;
	
        long  long  co[N];
long  long rem[N];
	std::set<std::pair<int, int> > cheap;
	for(int i = 0; i < N; i++)
		std::cin >> rem[i];
	
	for(int i = 0; i < N; i++)
	{
		std::cin >> co[i];
		cheap.insert({co[i], i});
	}
	
	for(int i = 0; i < M; i++)
	{
		long long earn = 0;
		int a;
                long long b;
		std::cin >> a >> b; a--;

		long long c = (long long)std::min(b, rem[a]);
		b -= c;
		rem[a] -= c;
		earn += c*co[a];

		while(b)
		{
			if(cheap.empty())
			{
				earn = 0;
				break;
			}
			
			int k = (*cheap.begin()).second;
			
			if(!rem[k])
			{
				cheap.erase(cheap.begin());
				continue;
			}
			
			int c = std::min(b, rem[k]);
			b -= c;
			rem[k] -= c;
			earn += c*co[k];
		}
		
		std::cout << earn << std::endl;
	}
	
	return 0;
}