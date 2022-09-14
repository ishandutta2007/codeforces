#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <string.h>
#include <assert.h>
#include <complex>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

const int INF = 2e9;


struct Person {
	int x, y;
	int id;
};

bool operator < (Person a, Person b) {
	return a.x > b.x;
}

int main() {
	// freopen("input.txt", "r", stdin);

	int n;
	int u, v;
	cin >> n >> u >> v;
	vector<Person> p(n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i].x;
		p[i].id = i;
	}

	for (int i = 0; i < n; ++i)
		cin >> p[i].y;

	sort(all(p));


	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
	vector<vector<int>> prev(n + 1, vector<int>(n + 1, 0));

	for (int i = 0; i < u; ++i)
		dp[0][0] += p[i].x;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			dp[i + 1][j] = dp[i][j];
		}
		for (int j = 0; j <= max(i, v - 1); ++j) {
		    
			if (j + u <= i) {
				if (dp[i + 1][j + 1] < dp[i][j] + p[i].y) {
					prev[i + 1][j + 1] = 1;
					dp[i + 1][j + 1] = dp[i][j] + p[i].y;
				}
			} else {
				if (dp[i + 1][j + 1] < dp[i][j] + p[i].y - p[i].x + p[j + u].x) {
					prev[i + 1][j + 1] = 1;
					dp[i + 1][j + 1] = dp[i][j] + p[i].y - p[i].x + p[j + u].x;
				}
			}
		}
	}

	cout << dp[n][v] << endl;

	vector<int> t1, t2;
	vector<int> used(n);

	int x = n, y = v;
	while (x != 0 || y != 0) {
		if (prev[x][y]) {
			t2.push_back(p[x - 1].id);
			used[p[x - 1].id] = 1;
			--x; --y;
		}
		else {
			--x;
		}
	}

	for (int i = 0; sz(t1) < u; ++i) {
		if (!used[p[i].id])
			t1.push_back(p[i].id);
	}

	for (int i = 0; i < sz(t1); ++i)
		cout << t1[i] + 1 << " ";
	cout << endl;
	for (int i = 0; i < sz(t2); ++i)
		cout << t2[i] + 1 << " ";
	cout << endl;
}