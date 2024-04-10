#include <iostream>
using namespace std;

int main() {
	ios :: sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int x = 0, y = 0, z = 0;
		for (int j = 0; j < s.size(); j++) {
			int a = s[j] - '0';
			if (a == 0) {
				x++;	
			}
			if (a % 2 == 0) {
				y++;
			}
			z += a;
		}
		if (x >= 1 && y >= 2 && z % 3 == 0) {
			cout << "red" << endl;
		}
		else {
			cout <<"cyan"  << endl;
		}
	}
	return 0;
}