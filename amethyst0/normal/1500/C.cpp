#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <limits.h>
#include <fstream>
#include <list>
#include <numeric>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
#define uint unsigned int
#define mp make_pair

const int maxn = 1510;

int val[maxn][maxn];
int cnt[maxn];
bool used[maxn];
bool ok[maxn];

int main() {
	int n, m;
	cin >> n >> m;

	vector <vector <int> > a(n, vector <int>(m));
	vector <vector <int> > b(n, vector <int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &b[i][j]);
		}
	}

	if (a == b) {
		cout << 0 << '\n';
		return 0;
	}

	int col = 0;
	auto cmp = [&](const vector <int> &a, const vector <int> &b) {
		return a[col] < b[col];
	};

	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n - 1; i++) {
			if (b[i][j] > b[i + 1][j]) {
				val[j][i] = 1;
				cnt[j]++;
			}
			else if (b[i][j] < b[i + 1][j]) {
				val[j][i] = -1;
			}
		}
	}

	vector <int> ans;

	while (true) {
		int cur = -1;

		for (int j = 0; j < m; j++) {
			if (used[j]) {
				continue;
			}

			if (cnt[j] == 0) {
				cur = j;
				break;
			}
		}

		if (cur == -1) {
			break;
		}

		used[cur] = true;

		ans.push_back(cur);
		for (int i = 0; i < n - 1; i++) {
			if (val[cur][i] == -1 && !ok[i]) {
				ok[i] = true;
				for (int k = 0; k < m; k++) {
					if (val[k][i] == 1) {
						cnt[k]--;
					}
				}
			}
		}
	}

	reverse(all(ans));
	for (int x : ans) { 
		col = x;
		stable_sort(a.begin(), a.end(), cmp);
	}

	if (a == b) {
		cout << ans.size() << '\n';
		for (int x : ans) {
			printf("%d ", x + 1);
		}
		cout << '\n';
	}
	else {
		cout << -1 << '\n';
	}
}