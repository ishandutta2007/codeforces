

#include <iostream>

bool chCount[26];

int main() {
	std::string str;
	std::cin >> str;
	for(char &c : str)
		chCount[c - 'a'] = !chCount[c - 'a'];
	
	int count = 0;
	for(auto x : chCount)
		if(x) ++count;
	
	std::cout << (count == 0 || count % 2 == 1 ? "First" : "Second");
}