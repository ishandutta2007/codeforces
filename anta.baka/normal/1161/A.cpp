#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <iomanip>
#include <string>
#include <string.h>
#include <cstdio>
#include <stdio.h>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cmath>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back

const int nax = 1e5;
const int inf = 1e9;

int n, k;
vi lo(nax, inf), hi(nax, -inf);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//ifstream cin("in.txt");
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		--x;
		lo[x] = min(i, lo[x]);
		hi[x] = max(i, hi[x]);
	}
	int cfree = 0;
	for (int i = 0; i < n; i++) {
		if (lo[i] == inf) {
			cfree++;
		}
	}
	int cl = 0;
	for (int i = 0; i < n - 1; i++) {
		if (lo[i] >= hi[i + 1]) {
			cl++;
		}
	}
	int cr = 0;
	for (int i = n - 1; i > 0; i--) {
		if (lo[i] >= hi[i - 1]) {
			cr++;
		}
	}
	cout << cfree + cl + cr;
}