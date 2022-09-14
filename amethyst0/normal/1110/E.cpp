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
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
//typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair

const int maxn = (int)1e5 + 10;
int c[maxn], t[maxn];

int main() {
	int n;

	cin >> n;

	vector <int> x, y;

	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i]);

		if (i != 0) {
			x.push_back(c[i] - c[i - 1]);
		}
	}

	for (int i = 0; i < n; i++) {
		scanf("%d", &t[i]);

		if (i != 0) {
			y.push_back(t[i] - t[i - 1]);
		}
	}

	if (c[0] != t[0] || c[n - 1] != t[n - 1]) {
		cout << "No\n";
		return 0;
	}

	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	for (int i = 0; i < (int)x.size(); i++) {
		//cout << x[i] << ' ' << y[i] << endl;
		if (x[i] != y[i]) {
			printf("No\n");
			return 0;
		}
	}

	printf("Yes\n");

	//system("pause");

	return 0;
}