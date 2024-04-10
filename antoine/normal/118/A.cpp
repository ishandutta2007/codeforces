#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

char v[] = {'a', 'o', 'y', 'e', 'u', 'i'};
char V[] = {'A', 'O', 'Y', 'E', 'U', 'I'};

bool isV(char c) {
	for(int i = 0; i < 6; ++i)
		if(c == v[i])
			return true;
	for(int i = 0; i < 6; ++i)
		if(c == V[i])
			return true;
		return false;
}

int main() {
	std::string s, o;
	std::cin >> s;
	o = "";
	
	for(int i = 0; i < s.length(); ++i) {
		if(!isV(s[i])) {
			if(s[i] >= 'A' && s[i] <= 'Z')
				s[i] = s[i] + 'a' - 'A';
			o = o+"." + s[i];
		}
	}
	std::cout << o;return 0;
}