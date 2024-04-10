#include <iostream>
#include <vector>
#include <stack>
#include <map>

#define int long long
#define MAX 2000000



signed main() {
	int x, y; int a, b;
	std::cin >> x >> y >> a >> b;
	
	int min = std::min(x, std::min(y, std::min(a, b)));
	//x -= min;y -= min;a -= min;b -= min;
	
	int countp = x+y;
	int countv = std::max(a, b);
	
	if(countp <= countv || (x <= a && y <= b))
		std::cout << "Polycarp";
	else
		std::cout << "Vasiliy";
}