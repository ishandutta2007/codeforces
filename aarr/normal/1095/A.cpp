#include <iostream>
using namespace std;

int main() {
	int n;
	string s;
	cin >> n;
	cin >> s;
	int j = 0;
	for (int i = 1; j < s.size(); i++) {
		cout << s[j];
		j += i;
	}
	return 0;
}