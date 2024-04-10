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
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; i++) {
			cin >> b[i];
		}
		sort(a + 1, a + n + 1, greater<int>());
		sort(b + 1, b + n + 1, greater<int>());
		int ans = 0;
		for (int q = 0; q <= k && q <= n; q++) {
			int s = 0;
			for (int i = 1; i <= q; i++) {
				s += b[i];
			}
			for (int i = 1; i <= n - q; i++) {
				s += a[i];
			}
			ans = max(ans, s);
		}
		cout << ans << endl;
		
	}
}