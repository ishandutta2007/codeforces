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
	int t = 1;
//	cin >> t;
	for (int ii = 0; ii < t; ii++) {
		int n;
		cin >> n;
		int ans = N - 1;
		a[ans] = N;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (i > 1 && abs(a[i] - a[i - 1]) < abs(a[ans] - a[ans - 1])) {
				ans = i;
			}
		}
		if (abs(a[ans] - a[ans - 1]) > abs(a[n] - a[1])) {
			cout << "1 " << n << endl;
		}
		else {
			cout << ans << " " << ans - 1 << endl;
		}
	}
}