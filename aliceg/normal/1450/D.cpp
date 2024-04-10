#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <functional>
#include <limits>
#include <ctime>
#include <random>
#include <bitset>
#include <numeric>
#include <complex>

#define pb push_back
#define mp make_pair
#define endl '\n'
#define sqr(x) ((x) * (x))
#define IOboost ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int ll

//#ifndef LOCALFILE
//#define _getchar_nolock getchar_unlocked
//#define _putchar_nolock putchar_unlocked
//#endif

#pragma warning(disable : 4996)
#pragma optimize("gtsy", on)
//#pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const ld PI = 3.141592653589793;
const ld EPS = 1e-8;
const int N = (int)3e5 + 10;
const int INF = (int)3e5 + 10;
const int MOD = (int)1e9 + 7;
const int K = 19;

bool perm(vector<int> a) {
	sort(a.begin(), a.end());
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] != i + 1)
			return 0;
	}
	return 1;
}

vector<int> p(N);

int find_min(int l, int r, vector<vector<int>>& a) {
	return min(a[l][p[r - l]], a[r - (1 << p[r - l])][p[r - l]]);
}

signed main() {
#ifdef LOCALFILE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	IOboost;

	for (int i = 2; i < N; ++i)
		p[i] = p[i / 2] + 1;

	int t;
	cin >> t;
	for (int j1 = 0; j1 < t; ++j1) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		vector<char> ans(n);
		vector<vector<int>> minn(n + 1, vector<int>(K, INF));
		for (int i = 0; i < n; ++i)
			minn[i][0] = a[i];
		for (int j = 1; j < K; ++j) {
			for (int i = 0; i < n; ++i) {
				if (i + (1 << (j - 1)) >= n)
					minn[i][j] = minn[i][j - 1];
				else
					minn[i][j] = min(minn[i][j - 1], minn[i + (1 << (j - 1))][j - 1]);
			}
		}
		if (perm(a))
			ans[0] = 1;
		int l = 0, r = n;
		int k = 1;
		for (int i = 0; i < n; ++i) {
			if (find_min(l, r, minn) > i + 1) {
				k = r - l + 1;
				break;
			}
			if (a[l] == i + 1) {
				if (find_min(l + 1, r, minn) <= i + 1) {
					k = r - l;
					break;
				}
				++l;
			}
			else if (a[r - 1] == i + 1) {
				if (find_min(l, r - 1, minn) <= i + 1) {
					k = r - l;
					break;
				}
				--r;
			}
			else {
				k = r - l;
				break;
			}
		}
		for (int i = k - 1; i < n; ++i)
			ans[i] = 1;
		for (int i = 0; i < n; ++i) {
			if (ans[i])
				cout << 1;
			else
				cout << 0;
		}
		cout << endl;
	}

	return 0;
}