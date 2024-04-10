#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <bitset>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <random>
#include <ctime>
#include <utility>

#pragma GCC optimize("O3")
#pragma comment(linker, "/STACK:256000000")
#pragma warning(disable:4996)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi1;
typedef vector<vi1> vi2;
typedef vector<ll> vll1;
typedef vector<vll1> vll2;

const int inf = 1e9;
const ll llinf = 1e18;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define all(v) v.begin(), v.end()

int main() {
	srand(time(NULL));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, q;
	cin >> n >> q;
	vector<int> a(n), lef(q, -1), righ(q, -1);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (!a[i]) continue;
		if (lef[a[i] - 1] == -1) lef[a[i] - 1] = i;
		righ[a[i] - 1] = i;
	}
	vector<pair<int, int>> pos(n, { -1, 0 });
	for (int i = q - 1; i + 1; --i)
		if (lef[i] >= 0) {
			if (lef[i] == righ[i]) pos[lef[i]] = { i, 2 };
			else {
				pos[lef[i]] = { i, 0 };
				pos[righ[i]] = { i, 1 };
			}
		}
	vector<int> stack;
	for (int i = 0; i < n; ++i) {
		if (pos[i].first == -1) {
			if (lef[q - 1] == -1 && a[i] == 0) {
				lef[q - 1] = righ[q - 1] = i;
				pos[i] = { q - 1, 2 };
			}
			if (a[i] > 0) {
				if (stack.back() != a[i] - 1) return cout << "NO", 0;
			}
			continue;
		}
		if (pos[i].second != 1) {
			if (stack.size() > 0 && stack.back() > pos[i].first) return cout << "NO", 0;
			stack.push_back(pos[i].first);
		}
		if (pos[i].second != 0) {
			if (stack.back() != pos[i].first) return cout << "NO", 0;
			stack.pop_back();
		}
	}
	if (lef[q - 1] == -1) return cout << "NO", 0;
	int mn = q - 1;
	for (int i = 0; i < q; ++i)
		if (lef[i] >= 0 && lef[i] < lef[mn]) mn = i;
	lef[mn] = 0;
	pos.assign(n, { -1, 0 });
	for (int i = q - 1; i + 1; --i)
		if (lef[i] + 1) {
			if (lef[i] == righ[i]) pos[lef[i]] = { i, 2 };
			else {
				pos[lef[i]] = { i, 0 };
				pos[righ[i]] = { i, 1 };
			}
		}
	cout << "YES\n";
	int last = -1;
	for (int i = 0; i < n; ++i) {
		if (pos[i].first == -1) {
			if (stack.size() > 0) cout << stack.back() + 1 << ' ';
			else
				cout << last + 1 << ' ';
			continue;
		}
		if (pos[i].second != 1) {
			if (stack.size() > 0 && stack.back() > pos[i].first) return cout << "NO", 0;
			stack.push_back(pos[i].first);
		}
		cout << pos[i].first + 1 << ' ';
		if (pos[i].second != 0) {
			if (stack.back() != pos[i].first) return cout << "NO", 0;
			stack.pop_back();
			last = pos[i].first;
		}
	}
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}