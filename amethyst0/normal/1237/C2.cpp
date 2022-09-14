//#pragma comment(linker, "/STACK:1000000000")
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
#include <cassert>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define ld double

using namespace std;

const int maxn = (int)1e5 + 10;

int x[maxn], y[maxn], z[maxn];
int g[3][maxn];

vector <int> v;

bool cmpx(int a, int b) {
	return x[a] < x[b];
}

bool cmpy(int a, int b) {
	return y[a] < y[b];
}

bool cmpz(int a, int b) {
	return z[a] < z[b];
}

int solve(vector <int> v, int tp) {
	if (tp == 0) {
		sort(v.begin(), v.end(), cmpx);
	}
	else if (tp == 1) {
		sort(v.begin(), v.end(), cmpy);
	}
	else {
		sort(v.begin(), v.end(), cmpz);
	}

	if (tp == 2) {
		for (int i = 0; i < (int)v.size() - 1; i += 2) {
			printf("%d %d\n", v[i] + 1, v[i + 1] + 1);
		}

		if ((int)v.size() % 2 == 1) {
			return v.back();
		}

		return -1;
	}
	else {
		int pos = 0;

		vector <int> lst;
		vector <int> f;

		while (pos < (int)v.size()) {
			int r = pos;

			while (r < (int)v.size() && g[tp][v[r]] == g[tp][v[pos]]) {
				r++;
			}

			if (pos < r) {
				f.clear();
				for (int i = pos; i < r; i++) {
					f.push_back(v[i]);
				}

				int x = solve(f, tp + 1);
				if (x != -1) {
					lst.push_back(x);
				}
			}

			pos = r;
		}

		for (int i = 0; i < (int)lst.size() - 1; i += 2) {
			printf("%d %d\n", lst[i] + 1, lst[i + 1] + 1);
		}

		if ((int)lst.size() % 2 == 1) {
			return lst.back();
		}

		return -1;
	}
}

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &x[i], &y[i], &z[i]);
		g[0][i] = x[i];
		g[1][i] = y[i];
		g[2][i] = z[i];
	}

	for (int i = 0; i < n; i++) {
		v.push_back(i);
	}

	solve(v, 0);

	//system("pause");
	return 0;
}