#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
int t;
std::cin >> t;
while(t--) {
	double n;
	std::cin >> n;

	double pi = 2*acos(0.0);

	double ans = ((double)(1))/sin(pi/(2*n));
	ans *= sin((n-1)*pi/(2*n));

	std::cout << std::setprecision(20) << ans << std::endl;
}
}