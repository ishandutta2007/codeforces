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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	ld mx = 0.;
	vector<int> pref(n, 0);
	pref[0] = a[0];
	for (int i = 1; i < n; ++i)
		pref[i] = pref[i - 1] + a[i];
	for (int len = k; len <= n; ++len)
		for (int i = 0; i + len <= n; ++i) {
			mx = max(mx, ld(pref[i + len - 1] - (i > 0 ? pref[i - 1] : 0)) / ld(len));
		}
	cout.precision(10);
	cout << fixed << mx;

#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}