#include <iostream>

#define MOD 1000000007

int main()
{
	long long answer = 1;
	
	std::string s;
	std::cin >> s;
	
	long long last = 0;
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] == 'a')
		{
			last++;
			//std::cout << last << " test " << std::endl;
		}
		if(s[i] == 'b')
		{
			answer *= last + 1;
			answer = (answer + MOD)%MOD;
			last = 0;
		}
	}
	
	answer *= last + 1;
	answer = (answer + MOD)%MOD;
	
	std::cout << (answer - 1 + MOD)%MOD;
	
	return 0;
}