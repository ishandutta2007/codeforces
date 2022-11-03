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
#include <numeric>
#include <functional>
#include <limits>
#include <ctime>
#include <random>
#include <bitset>
#include <numeric>
#include <complex>
#include <stdlib.h>
#include <cassert>

#define mp make_pair
#define endl '\n'
#define sqr(x) ((x) * (x))
#define IOboost ios_base::sync_with_stdio(false); cin.tie(NULL)
//#define int ll

#ifndef _getchar_nolock
#define _getchar_nolock getchar_unlocked
#define _putchar_nolock putchar_unlocked
#endif

#pragma warning(disable : 4996)
#pragma optimize("gtsy", on)
//#pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<char> vc;

const ld PI = 3.141592653589793;
const ld EPS = 1e-8;
const int N = (int)1e5 + 10;
const int INF = (int)1e9 + 10;
const int MOD = (int)1e9 + 7;
const int K = 18;

struct info {
	int left_sum, left_max, left_min, right_sum, right_max, right_min;
	info(int left_sum = 0, int left_max = 0, int left_min = 0, int right_sum = 0, int right_max = 0, int right_min = 0)\
		: left_sum(left_sum), left_max(left_max), left_min(left_min), right_sum(right_sum), right_max(right_max), right_min(right_min) {};
};

int max_suf[2 << K], min_suf[2 << K], max_pref[2 << K], min_pref[2 << K], sum[2 << K];

void change(int v, int L, int R, int i, int x) {
	if (R - L == 1) {
		max_suf[v] = x;
		min_suf[v] = x;
		max_pref[v] = x;
		min_pref[v] = x;
		sum[v] = x;
		return;
	}
	int M = (L + R) / 2;
	if (i < M)
		change(v * 2, L, M, i, x);
	else
		change(v * 2 + 1, M, R, i, x);
	max_suf[v] = max(max_suf[v * 2 + 1], sum[v * 2 + 1] + max_suf[v * 2]);
	min_suf[v] = min(min_suf[v * 2 + 1], sum[v * 2 + 1] + min_suf[v * 2]);
	max_pref[v] = max(max_pref[v * 2], sum[v * 2] + max_pref[v * 2 + 1]);
	min_pref[v] = min(min_pref[v * 2], sum[v * 2] + min_pref[v * 2 + 1]);
	sum[v] = sum[v * 2] + sum[v * 2 + 1];
	return;
}

info get(int v, int L, int R, int i) {
	if (R - L == 1)
		return { sum[v], sum[v], sum[v], sum[v], sum[v], sum[v] };
	int M = (L + R) / 2;
	if (i < M) {
		auto x = get(v * 2, L, M, i);
		x.right_max = max(x.right_max, max_pref[v * 2 + 1] + x.right_sum);
		x.right_min = min(x.right_min, min_pref[v * 2 + 1] + x.right_sum);
		x.right_sum += sum[v * 2 + 1];
		return x;
	}
	else {
		auto x = get(v * 2 + 1, M, R, i);
		x.left_max = max(x.left_max, max_suf[v * 2] + x.left_sum);
		x.left_min = min(x.left_min, min_suf[v * 2] + x.left_sum);
		x.left_sum += sum[v * 2];
		return x;
	}
}

int func(int x) {
	int y = abs(x) / 2;
	if (x > 0 && x % 2)
		++y;
	return y;
}

void solve() {

	int n;
	cin >> n;
	vvi a(n);
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		--x;
		a[x].push_back(i);
	}
	for (int i = 0; i < n; ++i)
		change(1, 0, 1 << K, i, 1);
	vi ans(n);
	for (int i = 0; i < n; ++i) {
		for (int j : a[i]) {
			auto x = get(1, 0, 1 << K, j);
			ans[j] = max(ans[j], func(x.left_max + x.right_max - 2));
			ans[j] = max(ans[j], func(x.left_min + x.right_min - 2));
		}
		for (int j : a[i])
			change(1, 0, 1 << K, j, -1);
		for (int j : a[i]) {
			auto x = get(1, 0, 1 << K, j);
			ans[j] = max(ans[j], func(x.left_max + x.right_max + 2));
			ans[j] = max(ans[j], func(x.left_min + x.right_min + 2));
		}
	}
	for (int i = 0; i < n; ++i)
		cout << ans[i] << ' ';

	return;
}

signed main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	IOboost;
	
	/*int t;
	cin >> t;
	for (int i = 0; i < t; ++i)*/
		solve();

	return 0;
}