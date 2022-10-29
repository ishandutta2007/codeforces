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

int ans[100][100];
int main() {
	srand(time(NULL));
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < m; ++i) cin >> b[i];
	vector<bool> a1(n), b1(m);
	for (int q = 0; q < 30; ++q) {
		int tmp = 1 << q, cl1 = 0, cl2 = 0;
		for (int i = 0; i < n; ++i) {
			a1[i] = a[i] & tmp;
			cl1 += a1[i];
		}
		for (int i = 0; i < m; ++i) {
			b1[i] = b[i] & tmp;
			cl2 += b1[i];
		}
		if ((cl1 + cl2) & 1) return cout << "NO\n", 0;
		int l = 0, r = 0;
		while (cl1 > 0 && cl2 > 0) {
			while (!a1[l]) l++;
			while (!b1[r]) r++;
			ans[l][r] += tmp;
			cl1--; cl2--;
			l++; r++;
		}
		if (cl1 == 0) {
			while (cl2 > 0) {
				while (!b1[r]) r++;
				ans[0][r] += tmp;
				cl2--; r++;
			}
		}
		else {
			while (cl1 > 0) {
				while (!a1[l]) l++;
				ans[l][0] += tmp;
				cl1--; l++;
			}
		}
	}
	cout << "YES\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cout << ans[i][j] << ' ';
		cout << '\n';
	}
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}