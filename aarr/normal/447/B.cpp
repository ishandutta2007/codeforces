#include <iostream>
#include <algorithm>
#include <set>
#include <iomanip>
#include <vector>
#include <cmath>
#include <map>

using namespace std;


const int N = 200 * 1000 + 5;
const int inf = 1000 * 1000 * 1000 + 7;

int a[N];
int b[N];
bool mark[N];
map <int, int> mp;


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
bool lucky(int x) {
	while (x) {
		if (x % 10 != 7 && x % 10 != 4) {
			return false;
		}
		x /= 10;
	}
	return true;
}
int bmm(int x, int y) {
	if (y == 0)
		return x;
	return bmm(y, x % y);
}
bool vow(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
		return true;
	}
	return false;
}
int main() {
	string s;
	int maxi = 0, k, ans = 0;
	cin >> s >> k;
	for (int i = 0; i < 26; i++) {
		cin >> a[i];
		maxi = max(maxi, a[i]);
	}
	for (int i = 0; i < s.size(); i++) {
		ans += a[s[i] - 'a'] * (i + 1);
	}
	ans += (2 * s.size() + k + 1) * k / 2 * maxi;
	cout << ans;
}