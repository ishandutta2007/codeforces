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

ll ask(int tp, int i, int j, int k) {
	cout << (3 - tp) << ' ' << i << ' ' << j << ' ' << k << endl;
	ll x;
	cin >> x;
	return x;
}

int main() {
	int n;
	cin >> n;
	
	int x = 2;

	for (int i = 3; i <= n; i++) {
		if (ask(1, 1, i, x) == 1) {
			x = i;
		}
	}

	vector <pair <ll, int> > sq;

	for (int j = 2; j <= n; j++) {
		if (j == x) {
			continue;
		}

		ll sqw = ask(2, 1, x, j);
		sq.push_back(mp(sqw, j));
	}

	sort(sq.begin(), sq.end());

	int lst = sq.back().second;

	vector <pair <ll, int> > a, b;

	for (int j = 0; j < (int)sq.size() - 1; j++) {
		if (ask(1, 1, lst, sq[j].second) > 0) {
			b.push_back(sq[j]);
		}
		else {
			a.push_back(sq[j]);
		}
	}

	reverse(b.begin(), b.end());

	cout << 0 << ' ' << 1 << ' ' << x;

	for (int i = 0; i < (int)a.size(); i++) {
		cout << ' ' << a[i].second;
	}

	cout << ' ' << lst;

	for (int i = 0; i < (int)b.size(); i++) {
		cout << ' ' << b[i].second;
	}

	cout << endl;

	//system("pause");
}