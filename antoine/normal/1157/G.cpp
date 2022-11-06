#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;

bool check(const vector<vector<int>> &a) {
	int last = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (a[i][j] < last)
				return false;
			else
				last = a[i][j];
	return true;
}
void f(const int c0, vector<vector<int>> a) {
	vector<int> cCol(m, 0);
	vector<int> cRow(n, 0);

	auto flipRow = [&](const int i) {
		cRow[i] ^= 1;
		for(int j = 0; j < m; ++j)
		a[i][j] ^= 1;
	};
	auto flipCol = [&](const int j) {
		cCol[j] ^= 1;
		for(int i = 0; i < n; ++i)
		a[i][j] ^= 1;
	};
	for (int j = 0; j < m; ++j) {
		if (a[0][j] != (j >= c0))
			flipCol(j);
	}

	for (int i = 1; i < n; ++i) {
		if (a[i - 1].back() == 1) {
			if (!a[i][0])
				flipRow(i);
		} else {
			if (a[i][0])
				flipRow(i);
		}
	}
/*	for(auto x : a)
		for(auto y : x)
			cout << y << endl;
	cout << endl;*/
	if (check(a)) {
		cout << "YES\n";
		for (int x : cRow)
			cout << x;
		cout << endl;
		for (int x : cCol)
			cout << x;
		cout << endl;
		exit(0);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;

	vector<vector<int>> a(n, vector<int>(m, 0));
	for (vector<int> &v : a)
		for (int &x : v)
			cin >> x;

	for (int c0 = 0; c0 <= m; ++c0)
		f(c0, a);
	cout << "NO";
	return 0;
}