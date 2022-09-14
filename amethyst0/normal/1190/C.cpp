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

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

int n, k;
const int maxn = (int)1e5 + 10;
char s[maxn];
int v[maxn];
int sum[maxn];

int get_sum(int l, int r) {
	if (l == 0) {
		return sum[r];
	}

	return sum[r] - sum[l - 1];
}

set <int> p[2];

int main() {
	cin >> n >> k;

	scanf("%s", s);

	for (int i = 0; i < n; i++) {
		v[i] = s[i] - '0';
	}

	int sums = 0;

	for (int i = 0; i < n; i++) {
		sums += v[i];
		sum[i] = sums;
		p[v[i]].insert(i);
	}

	for (int i = 0; i <= n - k; i++) {
		int x = 0;

		if (i != 0) {
			x += get_sum(0, i - 1);
		}

		if (i + k != n) {
			x += get_sum(i + k, n - 1);
		}

		if (x == 0 || x == n - k) {
			cout << "tokitsukaze" << endl;
			//system("pause");
			return 0;
		}
	}

	for (int i = 0; i <= n - k; i++) {
		for (int x = 0; x < 2; x++) {
			auto it = p[x].lower_bound(i);
			auto it1 = p[x].lower_bound(i + k);

			if (it != p[x].begin() && it1 != p[x].end()) {
				cout << "once again" << endl;
				//system("pause");
				return 0;
			}

			if (it == p[x].begin()) {
				it = p[x].end();
				it--;
				swap(it, it1);
			}
			else {
				it1 = it;
				it1--;
				it = p[x].begin();
			}

			if ((*it1) - (*it) + 1 > k) {
				cout << "once again" << endl;
				//system("pause");
				return 0;
			}
		}
	}

	cout << "quailty" << endl;
	
	//system("pause");
	return 0;
}