#include <iostream>
#include <vector>

std::string s;
std::vector<int> d;
std::vector<int> val;
std::vector<int> gcdn;

int gcd(int a, int b)
{
	if(a == 0)
		return b;
		
	return gcd(b%a, a);
}

int main()
{
	int n;
	std::cin >> n;
	std::cin >> s;
	
	gcdn.resize(n+1);
	val.resize(n+1);
	
	for(int i = 1; i <= n; i++)
	{
		if(n%i == 0)
			d.push_back(i);
		
		gcdn[gcd(i, n)]++;
	}
	
	int ans = 0;
	for(int x : d)
	{
		for(int i = 0; i < x; i++)
			val[i] = 0;
		
		for(int i = 0; i < n; i++)
			if(s[i] == '1')
				val[i%x]++;
		
		bool poss = true;
		for(int i = 0; i < x; i++)
			if(val[i]%2)
				poss = false;
		
		if(poss)
			ans += gcdn[x];
	}
	
	std::cout << ans << std::endl;
	return 0;
}