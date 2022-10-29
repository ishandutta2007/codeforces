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
#define int ll

signed main() {
	srand(time(NULL));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> b(n), a(n), mx(n);
	for (int i = 0; i < n; ++i)
		cin >> b[i];
	mx[0] = max(b[0], b[n - 1] + 1);
	for (int i = 1; i < n; ++i)
		mx[i] = max(b[i], b[i - 1] + 1);
	int k = -1;
	for (int i = 0; i < n; ++i)
		if (mx[i] == b[i]) {
			k = i;
			break;
		}
	if (k == -1) {
		if (b[0] == 0) {
			cout << "YES\n";
			for (int i = 0; i < n; ++i)
				cout << "1 ";
		}
		else
			cout << "NO\n";
		return 0;
	}
	a[k] = b[k];
	for (int i = k - 1; i + 1; --i) {
		if (mx[i] == b[i])
			a[i] = b[i];
		else {
			a[i] = (mx[i] - b[i] + a[i + 1] - 1) / a[i + 1] * a[i + 1];
			a[i] += b[i];
		}
	}
	a.push_back(a[0]);
	for (int i = n - 1; i > k; --i) {
		if (mx[i] == b[i])
			a[i] = b[i];
		else {
			a[i] = (mx[i] - b[i] + a[i + 1] - 1) / a[i + 1] * a[i + 1];
			a[i] += b[i];
		}
	}
	cout << "YES\n";
	for (int i = 0; i < n; ++i)
		cout << a[i] << ' ';
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}