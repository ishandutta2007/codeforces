#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<char, int>> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i].first >> v[i].second;
	vector<int> a(10, -1);
	for (int i = 0; i < 10; ++i) {
		for (int j = n - 1; j >= 0; --j) {
			if (v[j].first == '&' && !(v[j].second & (1 << i))) {
				a[i] = (a[i] == 2 ? 1 : 0);
				break;
			} else if (v[j].first == '|' && (v[j].second & (1 << i))) {
				a[i] = (a[i] == 2 ? 0 : 1);
				break;
			} else if (v[j].first == '^' && (v[j].second & (1 << i))) {
				a[i] = (a[i] == 2 ? -1 : 2);
			}
		}
	}
	int _and = 0;
	int _or = 0;
	int _xor = 0;
	for (int i = 0; i < 10; ++i) {
		if (a[i] != 0)
			_and += (1 << i);
		if (a[i] == 1)
			_or += (1 << i);
		if (a[i] == 2)
			_xor += (1 << i);
	}
	cout << 3 << endl;
	cout << "& " << _and << endl;
	cout << "| " << _or << endl;
	cout << "^ " << _xor << endl;
}