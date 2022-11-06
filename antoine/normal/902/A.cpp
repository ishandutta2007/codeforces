#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	
	int r = 0;
	while (n-- > 0) {
		int a, b;
		cin >> a >> b;
		if (a > r)
			break;
		r = max(r, b);
	}
	cout << (r >= m ? "YES" : "NO");
	return 0;
}