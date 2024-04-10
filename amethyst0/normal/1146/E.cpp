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
typedef long double ld;

map <int, int> ans;
set <int> s;
int sg;

int main() {
	int n, q;

	cin >> n >> q;

	sg = 1;

	vector <int> v;

	for (int i = 0; i < n; i++) {
		int x;

		scanf("%d", &x);

		v.push_back(x);
		s.insert(abs(x));
	}

	vector <pii> f;

	for (int i = 0; i < q; i++) {
		char c;
		int x;

		scanf(" %c %d", &c, &x);

		if (c == '<') {
			f.push_back(mp(0, x));
		}
		else {
			f.push_back(mp(1, x));
		}
	}

	while (!f.empty()) {
		int x = f.back().second;
		int c = f.back().first;
		f.pop_back();

		if (c == 1) {
			int y = abs(x);

			while (!s.empty() && ((*s.rbegin()) > y || ((*s.rbegin()) == y && x <= 0))) {
				int z = *s.rbegin();
				s.erase(z);
				ans[z] = -z * sg;
			}

			if (x < 0) {
				sg *= -1;
			}
		}
		else {
			int y = abs(x);

			while (!s.empty() && ((*s.rbegin()) > y || ((*s.rbegin()) == y && x >= 0))) {
				int z = *s.rbegin();
				s.erase(z);
				ans[z] = z * sg;
			}

			if (x > 0) {
				sg *= -1;
			}
		}
	}

	for (int i = 0; i < (int)v.size(); i++) {
		int x = v[i];

		if (ans.count(abs(x))) {
			printf("%d ", ans[abs(x)]);
		}
		else {
			printf("%d ", x * sg);
		}
	}

	//system("pause");

	return 0;
}