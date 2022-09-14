#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <complex>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
mt19937 rr(random_device{}());

int main() {
	// freopen("arithmetic.in", "r", stdin);
	// freopen("arithmetic.out", "w", stdout);

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> p(n + 2);

	bool f = false;
	for (int i = 2; i < n + 2; ++i) {
		if (p[i] == 0) {
			p[i] = 1;
			for (int j = 1; i * j < n + 2; ++j) {
				if (p[i * j] == 0) {
					p[i * j] = 2;
					f = true;
				}
			}
		}
	}

	cout << (f ? 2 : 1) << endl;

	for (int i = 2; i < n + 2; ++i)
		cout << p[i] << " ";
	cout << endl;
}