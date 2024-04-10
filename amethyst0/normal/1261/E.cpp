//#pragma comment(linker, "/STACK:1000000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
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
#define pll pair <ll, ll>
#define ld double

using namespace std;

const int maxn = 1010;
int v[maxn];
int ans[maxn][maxn];

int main() {
	int n;

	cin >> n;

	vector <set <int> > v;

	v.push_back(set <int>());

	for (int i = 0; i < n + 1; i++) {
		v.back().insert(i);
	}

	for (int i = 0; i < n; i++) {
		int x;

		cin >> x;

		while ((int)v.back().size() == 1) {
			v.pop_back();
		}

		set <int> s = v.back();
		v.pop_back();

		int a = *s.begin();
		s.erase(s.begin());
		int b = *s.begin();

		ans[b][i] = 1;

		set <int> fa, fb;
		fa.insert(a);
		fb.insert(b);

		x--;

		for (int j = 0; j <= n; j++) {
			if (j == a || j == b) {
				continue;
			}

			if (x != 0) {
				x--;
				ans[j][i] = 1;
				if (s.count(j)) {
					fb.insert(j);
				}
			}
			else {
				if (s.count(j)) {
					fa.insert(j);
				}
			}
		}

		v.push_back(fa);
		v.push_back(fb);
	}

	cout << n + 1 << '\n';

	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j];
		}

		cout << '\n';
	}

	//system("pause");
}