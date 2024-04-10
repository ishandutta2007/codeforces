#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

const int maxn = 1010;
int l[maxn], r[maxn];

int ans[maxn];
bool used[maxn];

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d", &l[i]);
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &r[i]);
	}

	int tot = 0;

	for (int i = n; i >= 1; i--) {
		vector <int> ps;
		int cn = 0;

		for (int j = 0; j < n; j++) {
			if (!used[j] && l[j] == 0 && r[j] == 0) {
				ps.push_back(j);
				cn++;
				used[j] = true;
				ans[j] = i;
				tot++;
			}
		}

		int cur = 0;

		for (int j = 0; j < n; j++) {
			if (used[j]) {
				continue;
			}

			while (cur < cn && ps[cur] < j) {
				cur++;
			}

			l[j] -= cur;
			r[j] -= (cn - cur);
		}
	}

	if (tot != n) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;

		for (int i = 0; i < n; i++) {
			cout << ans[i] << ' ';
		}

		cout << endl;
	}

	//system("pause");
}