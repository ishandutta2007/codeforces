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
	vector<int> a(n), c(n);
	for (int i = 0; i < n; ++i) cin >> c[i];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i]--;
	}
	vector<int> cl(n, -1), p(n, -1);
	int cnt = 1;
	for (int i = 0; i < n; ++i) {
		if (cl[i] == -1) {
			int v = i;
			while (cl[v] == -1) {
				cl[v] = cnt;
				v = a[v];
			}
			if (cl[v] != cnt) {
				for (int j = i; cl[j] == cnt; j = a[j]) cl[j] = 0;
			}
			else {
				for (int j = i; j != v; j = a[j]) {
					cl[j] = 0;
				}
				for (int j = a[v]; j != v; j = a[j])
					p[a[j]] = j;
				p[a[v]] = v;
				cnt++;
			}
		}
	}
	vector<int> ans(cnt - 1, inf);
	for (int i = 0; i < n; ++i) {
		if (cl[i] > 0)
			ans[cl[i] - 1] = min(ans[cl[i] - 1], c[i]);
	}
	int sum = 0;
	for (int i = 0; i < cnt - 1; ++i) sum += ans[i];
	cout << sum;
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}