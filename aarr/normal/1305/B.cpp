#include <bits/stdc++.h>
using namespace std;

vector <int> vec;
int main() {
	ios :: sync_with_stdio(false);
	string s;
	cin >> s;
	int x = 0, y = 0, z = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			x++;
		}
		else {
			y++;
		}
	}
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(' && z < y) {
			vec.push_back(i + 1);
			z++;
		}
		if (s[i] == ')') {
			y--;
			if (y < z) {
				vec.push_back(i + 1);
			}
		}
	}
	if (vec.size() == 0) {
		cout << 0;
		return 0;
	}
	cout << 1 << endl;
	cout << vec.size() << endl;
	for (auto x : vec) {
		cout << x << " ";
	}
	return 0;
}