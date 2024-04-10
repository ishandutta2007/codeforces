#include <iostream>


using namespace std;

int main() {
	int n;
	cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int s = 0;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (a[i] > a[j])
				++s;
	s = s % 2;
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		int k = y - x + 1;
		s += k * (k - 1) / 2;
		s = s % 2;
		if (s == 1)
			cout << "odd" << '\n';
		else
			cout << "even" << '\n';
	}
	return 0;
}