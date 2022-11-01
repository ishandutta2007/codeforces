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
	int n, s = 0, z = 0, c = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i == 1 || a[i] * 2 <= a[1]) {
			s += a[i];
			b[i] = true;
			c++;
		}
		z += a[i];
	}
	if (s * 2 > z) {
		cout << c << endl;
		for (int i = 1; i <= n; i++) {
			if (b[i]) {
				cout << i << " ";
			}
		}
	}
	else {
		cout << 0;
	}

}