#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int n, m;


int cc0(const int rr, const int cc) {
	return rr*m + cc;
}

bool defaultAdj0[100][100];
bool defaultAdj1[100][100];

void generateDefault() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i > 0)
				defaultAdj0[cc0(i, j)][cc0(i - 1, j)] = defaultAdj0[cc0(i - 1, j)][cc0(i, j)] = 1;
			if (j > 0)
				defaultAdj0[cc0(i, j)][cc0(i, j - 1)] = defaultAdj0[cc0(i, j - 1)][cc0(i, j)] = 1;
		}
	}
}

void check(vector<int> &v) {
	for (int i = 0; i < v.size(); ++i) {
		int r = i / m;
		int c = i % m;
		if (r > 0 && defaultAdj0[v[i] - 1][v[cc0(r - 1, c)] - 1]) {
			return;
		}
		if (c > 0 && defaultAdj0[v[i] - 1][v[cc0(r, c - 1)] - 1])
			return;
	}
	cout << "YES";
	for (int r = 0; r < n; ++r) {
		cout << '\n' << v[(r)*m];
		for (int c = 1; c < m; ++c) {
			cout << ' ' << v[(r)*m + (c)];
		}
	}
	cout << '\n';
	exit(0);
}

void mix(vector<int> &v) {
	for (int i = 0; i + 4 <= v.size(); i += 4) {
		vector<int> tmp = { v[i], v[i + 1], v[i + 2], v[i + 3] };
		v[i + 0] = tmp[2];
		v[i + 1] = tmp[0];
		v[i + 2] = tmp[3];
		v[i + 3] = tmp[1];
	}

	vector<int> tmp1;
	vector<int> tmp2;
	for (int i = (v.size() & ~(3)) - 4; i < (v.size() & ~(3)); ++i)
		tmp1.push_back(v[i]);
	for (int i = v.size() & ~(3); i < v.size(); ++i)
		tmp2.push_back(v[i]);
	tmp2.resize(4, 0);

	v.resize((v.size() & ~(3)) - 4);

	for (int i = 0; i < 4; ++i)  {
		if (tmp1[i])
			v.push_back(tmp1[i]);
		if (tmp2[i])
			v.push_back(tmp2[i]);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(nullptr);

	cin >> n >> m;

	if (n < 4 && m < 4) {
		for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 100; ++j)
			defaultAdj0[i][j] = false;
		generateDefault();


		std::vector<int> v(n*m);
		for (int i = 0; i < v.size(); ++i)
			v[i] = i + 1;
		do {
			check(v);
		} while (std::next_permutation(v.begin(), v.begin() + v.size()));
		cout << "NO";
		cout << '\n';
		return 0;
	}

	bool rotated = m < n;
	std::vector<vector<int>> vv(n, vector<int>(m));
	for (int i = 0; i < n; ++i)
	for (int j = 0; j < m; ++j)
		vv[i][j] = cc0(i, j) + 1;

	if (rotated) {
		std::vector<vector<int>> vv2(m, vector<int>(n));
		for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			vv2[j][i] = vv[i][j];
		vv = vv2;
		std::swap(n, m);
	}

	for (int i = 0; i < n; ++i) {
		mix(vv[i]);
		if (i & 1) {
			if (m & 1)
				std::rotate(vv[i].begin(), vv[i].begin() + 1, vv[i].end());
			else
				std::reverse(vv[i].begin(), vv[i].end());
		}
	}

	if (rotated) {
		std::vector<vector<int>> vv2(m, vector<int>(n));
		for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			vv2[j][i] = vv[i][j];
		vv = vv2;
		std::swap(n, m);
	}

	cout << "YES";
	for (int r = 0; r < n; ++r) {
		cout << '\n' << vv[r][0];
		for (int c = 1; c < m; ++c) {
			cout << ' ' << vv[r][c];
		}
	}
	cout << '\n';
	return 0;
}