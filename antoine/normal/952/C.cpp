#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>

using namespace std;
typedef long long ll;

bool f(vector<int> &a) {
	bool res = false;
	for (int i = 0; i + 1 < a.size(); ++i) {
		while (a[i] > a[i + 1] + 1) {
			a[i]--;
			a[i + 1]++;
			res = true;
		}
		while (a[i + 1] > a[i] + 1) {
			a[i + 1]--;
			a[i]++;
			res = true;
		}
	}
	return res;
}

int g(vector<int> &a) {
	auto it = a.begin();
	for (int i = 1; i < a.size(); ++i)
		if (a[i] > *it)
			it = a.begin() + i;
	auto res = *it;
	a.erase(it);
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	auto a_sorted = a;
	sort(a_sorted.begin(), a_sorted.end());

	vector<int> res;

	for (int i = 0; i < n; ++i) {
		while (f(a));
		res.insert(res.begin(), g(a));
	}
	cout << (res == a_sorted ? "YES" : "NO");
	return 0;
}