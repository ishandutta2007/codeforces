#include <iostream>
#include <map>
using namespace std;

map <pair <char, char>, int> mp;

int main() {
	int y, b, r, ans = 105;
	cin >> y >> b >> r;
	ans = min(ans, r - 1);
	ans = min(ans, b);
	ans = min(ans, y + 1);
	cout << ans * 3;
	return 0;
}