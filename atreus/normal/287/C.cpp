#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	if (n % 4 == 2 || n % 4 == 3)
		return cout << -1, 0;
	if (n % 4 == 0){
		for (int i = 2; i <= n / 2; i += 2)
			cout << i << " " << n - i + 2 << " ";
		for (int i = n / 2 - 1; i >= 1; i -= 2)
			cout << i << " " << n - i << " ";
	}
	if (n % 4 == 1){
		for (int i = 2; i <= n / 2; i += 2)
			cout << i << " " << n - i + 2 << " ";
		cout << n / 2 + 1 << " ";
		for (int i = n / 2 - 1; i >= 1; i -= 2)
			cout << i << " " << n - i << " ";
	}
	return 0;

}