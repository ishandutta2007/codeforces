#include <iostream>
#include <string>
#include <map>
#include <algorithm>

signed main() {
	int n, m;
	std::cin >> n >> m;
	
	std::string s;
	std::string palin = "";
	std::map<std::string, int> map;
	for(int i = 0; i < n; i++) {
		std::string p;
		std::cin >> p;
		std::string q = p;
		std::reverse(q.begin(), q.end());
		if(map[q])
			s += p;
		else if(q == p) {
			palin = p;
		}
		map[p] = 1;
	}
	
	std::string t = s;
	std::reverse(t.begin(), t.end());
	s += palin;
	s += t;
	
	std::cout << s.length() << std::endl;
	std::cout << s;
}