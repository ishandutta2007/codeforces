#include <iostream>
#include <map>
#include <set>
using namespace std;


int main() {
	int x = 0, y = 0;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'o') {
			x++;
		}
	}
	if (x == 0 || s.size() % x == 0) {
		cout << "YES";
	}	
	else {
		cout << "NO";
	}
	return 0;
}