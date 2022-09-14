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

const int maxn = (int)1e6 + 10;
struct vt {
	ll sum;
	int len;

	vt() {

	}

	vt(ll sum, int len) : sum(sum), len(len) {

	}
};

bool operator <(vt a, vt b) {
	return a.sum * b.len < b.sum * a.len;
}

int v[maxn];

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	vector <vt> g;

	for (int i = n - 1; i >= 0; i--) {
		vt a = vt(v[i], 1);

		while (!g.empty() && g.back() < a) {
			a.sum += g.back().sum;
			a.len += g.back().len;
			g.pop_back();
		}

		g.push_back(a);
	}

	reverse(all(g));

	for (vt f : g) {
		for (int i = 0; i < f.len; i++) {
			printf("%.10lf ", (ld)f.sum / f.len);
		}
	}
}