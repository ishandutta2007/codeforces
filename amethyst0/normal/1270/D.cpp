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

const int maxn = (int)2e5 + 10;
int v[maxn];

int main() {
	int n, k;

	cin >> n >> k;

	if (k == 1) {
		cout << "! " << 1 << endl;
		return 0;
	}

	cout << "?";
	vector <int> a;

	for (int i = 0; i < k; i++) {
		cout << ' ' << i + 1;
		a.push_back(i);
	}

	cout << endl;

	int pos, x;

	cin >> pos >> x;
	pos--;

	cout << "?";

	vector <int> b;

	for (int i = 0; i < k + 1; i++) {
		if (i != pos) {
			cout << ' ' << i + 1;
			b.push_back(i);
		}
	}

	cout << endl;

	int pos1, x1;
	cin >> pos1 >> x1;
	pos1--;

	if (x < x1) {
		swap(x, x1);
		swap(pos, pos1);
		swap(a, b);
	}

	int cnt = 0;

	for (int j = 0; j < (int)a.size(); j++) {
		if (a[j] == pos) {
			continue;
		}
		cout << "?";
		for (int i = 0; i < k + 1; i++) {
			if (i != a[j]) {
				cout << ' ' << i + 1;
			}
		}

		cout << endl;

		int p, y;

		cin >> p >> y;
		p--;

		if (p == pos) {
			cnt++;
		}
	}

	cout << "! " << cnt + 1 << endl;

	return 0;
}