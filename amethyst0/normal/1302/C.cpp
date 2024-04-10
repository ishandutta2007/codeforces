#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
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
#include <fstream>
#include <bitset>
#include <limits.h>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>
#define uint int

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

const int maxn = (int)1e5 + 10;
vector <int> v;

vector <int> ans;

void solve(vector <int> &v, int b) {
	if (b == -1) {
		for (int x : v) {
			ans.push_back(x);
		}

		return;
	}

	int numb = 0;
	int pos = -1;

	for (int i = 0; i < (int)v.size(); i++) {
		if ((v[i] >> b) & 1) {
			numb++;
			pos = i;
		}
	}

	if (numb == 1) {
		ans.push_back(v[pos]);
		swap(v[pos], v.back());
		v.pop_back();
		solve(v, b - 1);
	}
	else {
		solve(v, b - 1);
	}
}

int main() {
	int n;

	cin >> n;
	v.resize(n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	solve(v, 29);

	for (int x : ans) {
		printf("%d ", x);
	}
}