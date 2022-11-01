#include <iostream>
using namespace std;

int main() {
	int s, v1, v2, t1, t2;
	cin >> s >> v1 >> v2 >> t1 >> t2;
	int x1 = s * v1 + 2 * t1, x2 = s * v2 + 2 * t2;
	if (x1 < x2)
		cout << "First" << endl;
	if (x1 > x2)
		cout << "Second" << endl;
	if (x1 == x2)
		cout << "Friendship" << endl;
	return 0;
}