#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <bitset>
#include <random>
//#include <priority_queue>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ld long double
#define pii pair <int, int>
#define ll long long

using namespace std;

int main() {
	int n, m;

	cin >> n >> m;

	vector <int> v(n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	sort(v.begin(), v.end());

	vector <int> h;

	for (int i = 0; i < m; i++) {
		int x1, x2, y;

		scanf("%d %d %d", &x1, &x2, &y);

		if (x1 == 1) {
			h.push_back(x2);
		}
	}

	sort(h.begin(), h.end());

	int ans = n + m;

	int pos = 0;

	for (int i = 0; i <= (int)v.size(); i++) {
		int r = (int)1e9;

		if (i != (int)v.size()) {
			r = v[i];
		}

		while (pos < (int)h.size() && h[pos] < r) {
			pos++;
		}

		ans = min(ans, i + (int)h.size() - pos);
	}

	cout << ans << endl;

	//system("pause");
}