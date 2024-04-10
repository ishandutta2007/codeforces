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
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ii++) {
		int n, c = 0, d = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (i % 2 == 1 && a[i] % 2 == 0) {
				c++;
			}
			if (i % 2 == 0 && a[i] % 2 == 1) {
				d++;
			}
		}
		if (c == d) {
			cout << c << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
}