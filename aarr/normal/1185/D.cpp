#include <iostream>
#include <algorithm>
using namespace std;

const int N = 200 * 1000 + 5;
int n;

pair <int, int> a[N];
bool zero() {
	for (int i = 2; i < n; i++) {
		if (a[i].first - a[i - 1].first != a[2].first - a[1].first)
			return false;
	}
	return true;
}
bool last() {
	for (int i = 1; i < n - 1; i++) {
		if (a[i].first - a[i - 1].first != a[1].first - a[0].first)
			return false;
	}
	return true;
}
bool one() {
	for (int i = 3; i < n; i++) {
		if (a[i].first - a[i - 1].first != a[2].first - a[0].first)
			return false;
	}
	return true;
}
int f() {
	if (zero())
		return a[0].second + 1;
	if (one())
		return a[1].second + 1;
	if (last())
		return a[n - 1].second + 1;
	int j = -1;
	for (int i = 1; i < n; i++) {
		if (a[i].first - a[i - 1].first != a[1].first - a[0].first)
			j = i;
	}
	//cout << j << endl;
	if (a[j].first - a[j - 2].first != a[1].first - a[0].first)
		return -1;
	for (int i = 1; i < n; i++) {
		if (i != j && i != j - 1 && a[i].first - a[i - 1].first != a[1].first - a[0].first)
			return -1;
	}
	return a[j - 1].second + 1;
}
int main() {
	cin >> n;
	if (n <= 3) {
		cout << 1;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		//cout << a[i].first << " " << a[i].second << endl;
	}
	cout << f();
	return 0;
}