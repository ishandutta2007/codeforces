#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>
#include <array>
#include <memory>
#include <assert.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	
	struct Seg {
		int i, l, r;
		bool operator<(const Seg &other) {
			if (l != other.l) return l < other.l;
			return r > other.r;
		}
	};

	int n;
	cin >> n;
	vector<Seg> a(n);
	for (int i = 0; i < n; ++i) {
		a[i].i = i + 1;
		cin >> a[i].l >> a[i].r;
	}
	sort(a.begin(), a.end());
	for(int i = 0; i  + 1 < n; ++i)
		if (a[i].r >= a[i + 1].r) {
			cout << a[i + 1].i << ' ' << a[i].i;
			return 0;
		}
	cout << "-1 -1";
	return 0;
}