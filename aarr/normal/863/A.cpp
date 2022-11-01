#include <iostream>
#include <algorithm>
#include <set>
#include <iomanip>
#include <vector>
using namespace std;


const int N = 105;
int cnt[N];


int get(int x, int y) {
	return (x >> y) & 1;
}
int main() {
	string s;
	cin >> s;
	bool b = true;
	int x = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != '0') {
			x = i + 1;
		}
	}
	for (int i = 0; i < x; i++) {
		if (s[i] != s[x - i - 1]) {
			b = false;
		}
	}
	if (b)
		cout << "YES";
	else
		cout << "NO";
}