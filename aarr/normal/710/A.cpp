#include <iostream>
#include <iomanip>
#include <deque>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

const int N = 200 * 1000 + 5;

int a[N];
map <string, int> mp;
int b[N];
vector <char> vec;
deque <int> q;
bool mark[N];
char c[55][55];
string s[10], t[10];

bool get(int l, int r) {
	for (int i = 0; i <= r - l; i++) {
		if (s[l + i] != s[r - i]) {
			return false;
		}
	}
	return true;
}

int main() {
	char c;
	int x, y, z = 0;
	cin >> c >> y;
	x = c - 'a' + 1;
	if (x % 8 <= 1) {
		z++;
	}
	if (y % 8 <= 1) {
		z++;
	}
	if (z == 0) {
		cout << "8\n";
	}
	if (z == 1) {
		cout << "5\n";
	}
	if (z == 2) {
		cout << "3\n";
	}
}