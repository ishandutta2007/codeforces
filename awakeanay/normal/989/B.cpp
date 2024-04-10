#include <iostream>
#include <iomanip>

#define int long long

std::string s;
int p, n;

bool check() {
	bool ret = false;
	for(int i = p; i < n; i++) {
		if(s[i] != s[i-p])
			ret = true;
	}
	return ret;
}

signed main() {
	std::cin >> n >> p;
	
	std::cin >> s;
	
	int root = -1;
	for(int i = 0; i < n; i++) {
		if(s[i] == '.') {
			if(root > -1)
				s[root] = (i%2) ? '1' : '0';
			root = i;
		}
	}
	
	if(root == -1) {
		if(check())
			std::cout << s;
		else
			std::cout << "No";
		std::cout << std::endl;
		return 0;
	}
	
	s[root] = '0';
	if(!check()) {
		s[root] = '1';
		if(!check()) {
			std::cout << "No" << std::endl;
			return 0;
		}
	}
		
	std::cout << s << std::endl;
	
	return 0;
}