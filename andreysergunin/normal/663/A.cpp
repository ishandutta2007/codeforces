#include <string>
#include <queue>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <set>
#include <iostream>
#include <cassert>
#include <utility>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

int main() {
	int n;
	vector<char> s;
	int p = 1, m = 0;
	s.push_back('+');
	for (int i = 0; ; ++i) {
		char c;
		cin >> c >> c;
		s.push_back(c);
		if (c == '=')
			break;
		if (c == '+')
			++p;
		else
			++m;
	}
    s.pop_back();
	cin >> n;
	if (p * n - m >= n && n >= p - m * n)
		cout << "Possible" << endl;
	else {
		cout << "Impossible" << endl;
		return 0;
	}
	int k = sz(s);
	vector<int> a(k);
	for (int i = 0; i < k; ++i)
		a[i] = 1;
	if (p - m >= n) {
		int t = p - m - n;
		for (int i = 0; i < k; ++i) {
			if (s[i] == '-') {
				a[i] += min(t, n - 1);
				t -= min(t, n - 1);
			}
		}
	}
	else {
		int t = n - p + m;
		for (int i = 0; i < k; ++i) {
			if (s[i] == '+') {
				a[i] += min(t, n - 1);
				t -= min(t, n - 1);
			}
		}
	}

	cout << a[0] << " ";
	for (int i = 1; i < k; ++i)
		cout << s[i] << " " << a[i] << " ";
	cout << "= " << n << endl;


    return 0;
}