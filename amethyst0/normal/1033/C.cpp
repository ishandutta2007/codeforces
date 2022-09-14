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
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
//typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;
#define mp make_pair

const int maxn = (int)1e5 + 10;
int a[maxn];

int ans[maxn];

int main() {
	int n;
	cin >> n;

	vector <pii> v;

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		v.push_back(mp(-a[i], i));
	}

	sort(v.begin(), v.end());

	for (int it = 0; it < (int)v.size(); it++) {
		int i = v[it].second;

		int x = a[i];

		for (int d = 0; d <= n; d += x) {
			int ps = i - d;

			if (ps >= 0 && a[ps] > x && ans[ps] == 0) {
				ans[i] = 1;
			}

			ps = i + d;

			if (ps < n && a[ps] > x && ans[ps] == 0) {
				ans[i] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (ans[i]) {
			printf("A");
		}
		else {
			printf("B");
		}
	}

	//system("pause");
}