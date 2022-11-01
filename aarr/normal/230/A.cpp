#include <iostream>
#include <algorithm>
#include <set>
#include <iomanip>
#include <vector>
#include <cmath>
 
using namespace std;
 
 
const int N = 100 * 1000 + 5;
 
pair<int, int> a[N];
 
 
 
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
int main() {
	int s, n;
	cin >> s >> n;
	for (int i = 0; i < n; i++) {
	    cin >> a[i].first >> a[i].second;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		if (s <= a[i].first) {
			cout << "NO";
			return 0;
		}
		s += a[i].second;
	}
	cout << "YES";
}