#include <iostream>

int main() {
	int n, m;
	std::cin >> n >> m;
	
	std::string a[n], b[m];
	for(int i = 0; i < n; i++)
		std::cin >> a[i];
	for(int i = 0; i < m; i++)
		std::cin >> b[i];
		
	int q;
	std::cin >> q;
	
	for(int i = 0; i < q; i++) {
		int x;
		std::cin >> x;
		x--;
		std::cout << a[x%n] << b[x%m] << std::endl;
	}
	return 0;
}