#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <cstring>
#include <memory.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int maxn = (int)3e5 + 10;
bool used[maxn];

int main() {
	int t;

	cin >> t;

	while (t--) {
		int n, m;

		scanf("%d %d", &n, &m);

		for (int i = 1; i <= 3 * n; i++) {
			used[i] = false;
		}

		vector <int> ans;

		for (int i = 0; i < m; i++) {
			int x, y;

			scanf("%d %d", &x, &y);

			if (!used[x] && !used[y]) {
				ans.push_back(i + 1);
				used[x] = true;
				used[y] = true;
			}
		}

		if ((int)ans.size() > n) {
			printf("Matching\n");

			for (int i = 0; i < n; i++) {
				printf("%d ", ans[i]);
			}

			printf("\n");
		}
		else {
			printf("IndSet\n");
			int cnt = 0;

			for (int i = 1; i <= 3 * n && cnt < n; i++) {
				if (!used[i]) {
					printf("%d ", i);
					cnt++;
				}
			}

			printf("\n");
		}
	}

	//system("pause");
}