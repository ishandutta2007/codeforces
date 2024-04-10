#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<pair<pair<int, int>, pair<int, int> > > A(N);
	map<int, vector<int> > mp1[3];
	map<int, vector<int> > mp2[3];
	int B = 1e9;
	vector<int> r(N, 0);
	for (int i = 0; i < N; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		A[i].first.first = x; A[i].first.second = y; A[i].second.first = z;
		A[i].second.second = i + 1;
	}
	sort(A.begin(), A.end());
	for (int i = 0; i < N; i++) {
		int x, y, z;
		x = A[i].first.first; y = A[i].first.second; z = A[i].second.first;
		mp1[0][x * B + y].push_back(i);
		mp1[1][y * B + z].push_back(i);
		mp1[2][z * B + x].push_back(i);
		mp2[0][x].push_back(i);
		mp2[1][y].push_back(i);
		mp2[2][z].push_back(i);
	}
	vector<pair<int, int> > res;

	int z = -1;
	for (int i = 0; i < 3; i++) {
		for (const auto &m : mp1[i]) {
			const vector<int> &t = m.second;
			z = -1;
			for (int j = 0; j < t.size(); j++) {
				if (r[t[j]] == 0) {
					if (z == -1) {
						z = t[j];
					}
					else {
						res.emplace_back(z, t[j]);
						r[z] = 1;
						r[t[j]] = 1;
						z = -1;
					}
				}
			}
		}
	}
	
	for (int i = 0; i < 3; i++) {
		for (const auto &m : mp2[i]) {
			const vector<int> &t = m.second;
			z = -1;
			for (int j = 0; j < t.size(); j++) {
				if (r[t[j]] == 0) {
					if (z == -1) {
						z = t[j];
					}
					else {
						res.emplace_back(z, t[j]);
						r[z] = 1;
						r[t[j]] = 1;
						z = -1;
					}
				}
			}
		}
	}

	
	z = -1;
	for (int j = 0; j < N; j++) {
		if (r[j] == 0) {
			if (z == -1) {
				z = j;
			}
			else {
				res.emplace_back(z, j);
				r[z] = 1;
				r[j] = 1;
				z = -1;
			}
		}
	}
	for (int i = 0; i < res.size(); i++) {
		cout << A[res[i].first].second.second << " " << A[res[i].second].second.second << '\n';
	}
	return 0;
}