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
vector <int> vec;
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
	int n, ans = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (n / i < i) {
			break;
		}
		if (n % i == 0) {
			ans = i;
		}
	}
	cout << ans << " " << n / ans;
}