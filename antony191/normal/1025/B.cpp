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
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i].first >> a[i].second;
	int t = a[0].first;
	vector<int> pr;
	for (int i = 2; i * 1ll * i <= t; ++i) {
		if (t % i == 0) {
			pr.push_back(i);
			while (t % i == 0) t /= i;
		}
	}
	if (t > 1) pr.push_back(t);
	for (int i = 0; i < pr.size(); ++i) {
		bool k = 1;
		for (int j = 1; j < n; ++j)
			if (a[j].first % pr[i] && a[j].second % pr[i]) {
				k = 0;
				break;
			}
		if (k)
			return cout << pr[i], 0;
	}

	t = a[0].second;
	pr.clear();
	for (int i = 2; i * 1ll * i <= t; ++i) {
		if (t % i == 0) {
			pr.push_back(i);
			while (t % i == 0) t /= i;
		}
	}
	if (t > 1) pr.push_back(t);
	for (int i = 0; i < pr.size(); ++i) {
		bool k = 1;
		for (int j = 1; j < n; ++j)
			if (a[j].first % pr[i] && a[j].second % pr[i]) {
				k = 0;
				break;
			}
		if (k)
			return cout << pr[i], 0;
	}
	cout << -1;
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}