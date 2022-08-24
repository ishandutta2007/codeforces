#include <bits/stdc++.h>
#define int long long
#define m_p make_pair
using namespace std;



main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	vector <pair <int, pair <int, int> > > x;
	int n, x0, y0, xi, yi;
	cin >> n >> x0 >> y0;
	vector <int> x_(n);
	vector <int> y_(n);
	vector <int> color(n);
	for (int i = 0; i < n; i++) {
		cin >> xi >> yi;
		x_[i] = xi;
		y_[i] = yi;
		color[i] = i;
		int a = yi - y0;
		int b = x0 - xi;
		int c = xi * y0 - x0 * yi;
		x.push_back(m_p(a, m_p(b, c)));
	}
	int p = n;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (color[j] == j && color[i] == i && x[j].first * x_[i] + x[j].second.first * y_[i] + x[j].second.second == 0) {
				p--;
				color[j] = color[i];
			}
		}
	}
	cout << p << endl;
}