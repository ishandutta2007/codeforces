#include <iostream>
#include <algorithm>
#include <set>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;


const int N = 305;

int cnt[N];



int get(int x, int y) {
	return (x >> y) & 1;
}
bool pal(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != s[s.size() - i - 1]) {
			return false;
		}
	}
	return true;
}
int main() {
	int a, b, c, n, ans = 0;
	cin >> a >> b >> c >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x > b && x < c) {
			ans++;
		}
	}
	cout << ans;
}