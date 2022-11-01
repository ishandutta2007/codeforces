#include <iostream>
#include <deque>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

const int N = 200 * 1000 + 5;

int a[N];
vector <int> vec;
deque <int> q;
bool mark[N];

int main() {
	int n, ans = 0, s = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		if (s * 2 < 9 * n) {
			ans++;
			s += 5 - a[i];
		}
	}
	cout << ans;
}