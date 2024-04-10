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
vector <int> vec1, vec2;


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
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x % 2) {
			vec1.push_back(x);
		}
		else {
			vec2.push_back(x);
		}
	}
	sort(vec1.begin(), vec1.end());
	sort(vec2.begin(), vec2.end());
//	cout << vec1.size() << " " << vec2.size() << endl;
 	if (vec1.size() < vec2.size()) {
		vec1.swap(vec2);
	}
//	cout << vec1.size() << " " << vec2.size() << endl;
	for (int i = 0; i < (int) vec1.size() - (int) vec2.size() - 1; i++) {
		ans += vec1[i];
	}
	cout << ans;
}