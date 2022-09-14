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
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	sort(all(a));

	if (a[0] == a.back()) {
		cout << 0 << endl;
		return 0;
	}

	int l = 0;
	for (; a[l] == a[0]; ++l);
	int r = n - 1;
	for (; a[r] == a.back(); --r);

	cout << r - l + 1 << endl;

}