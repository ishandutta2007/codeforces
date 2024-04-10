
#include <iostream>

int main() {
	int n;
	std::cin >> n;
	int arr[100];
	int sum = 0;
	for(int i = 0; i < n; ++i) {
		std::cin >> arr[i];
		sum += arr[i];
	}
	if(sum != 0) {
		std::cout << "YES\n1\n1 " << n;
		return 0;
	}
	for(int i = 0; i < n; ++i) {
		sum += arr[i];
		if(sum != 0) {
			std::cout << "YES\n2\n1 " << (i + 1) << "\n" << (i + 2) << " " << n;
			return 0;
		}
	}
	std::cout << "NO";
}