#include <iostream>

std::string r;
void send(std::string t)
{
	std::cout << "? ";
	for(int i = 0; i < t.length(); i++)
		std::cout << t[i];
	std::cout << std::endl;
	std::cin >> r;
}

int main()
{
	std::string s, t;
	std::cin >> s;
	t = s;
	int n = s.length();
	int swi[n];
	for(int i = 0; i < n; i++)
		swi[i] = 0;
	
	int pow[3];
	pow[0] = 1;
	pow[1] = 26;
	pow[2] = 26*26;
	
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < n; j++)
			t[j] = (j/pow[i])%26 + 'a';
			
		send(t);
		//std::cout << r << std::endl;
		for(int j = 0; j < n; j++)
			swi[j] += (r[j]-'a')*pow[i];
	}
	
	//for(int i = 0; i < n; i++)
	//	std::cout << swi[i] << std::endl;
	
	int rev[n];
	for(int i = 0; i < n; i++)
		rev[swi[i]] = i;
	
	std::cout << "! ";
	for(int i = 0; i < n; i++)
		std::cout << s[rev[i]];
	std::cout << std::endl;
	
	return 0;
}