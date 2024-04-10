#include <iostream>
#include <map>

int main() {
	std::map<std::string, int> m;
	m["Tetrahedron"] = 4;
	m["Cube"] = 6;
	m["Octahedron"] = 8;
	m["Dodecahedron"] = 12;
	m["Icosahedron"] = 20;
	
	int n;
	std::cin >> n;
	
	int ans = 0;
	
	for(int i = 0; i < n; i++) {
		std::string s;
		std::cin >> s;
		ans += m[s];
	}
	
	std::cout << ans;
	
	return 0;
}