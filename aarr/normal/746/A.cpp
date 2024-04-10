#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int ans = min(a, b / 2);
	ans = min(ans, c / 4);
	cout << ans * 7;
	return 0;
}