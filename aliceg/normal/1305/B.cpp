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
//#define int ll

#ifndef LOCALFILE
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

const ld EPS = 1e-6;
const int N = (int)1e6 + 10;
const int INF = (int)1e9 + 10;
const int MOD = (int)1e9 + 7;

signed main() {
#ifdef LOCALFILE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	IOboost;

	string s;
	cin >> s;
	int n = (int)s.length();
	vector<int> pref(n + 1), suf(n + 1);
	for (int i = 0; i < n; ++i) {
		pref[i + 1] = pref[i];
		if (s[i] == '(')
			++pref[i + 1];
	}
	for (int i = n - 1; i >= 0; --i) {
		suf[i] = suf[i + 1];
		if (s[i] == ')')
			++suf[i];
	}
	int j = 0;
	for (int i = 0; i <= n; ++i) {
		if (pref[i] == suf[i]) {
			j = i;
			break;
		}
	}
	vector<int> a;
	for (int i = 0; i < n; ++i) {
		if (i < j && s[i] == '(')
			a.pb(i + 1);
		if (i >= j && s[i] == ')')
			a.pb(i + 1);
	}
	if (a.empty())
		cout << 0;
	else {
		cout << "1\n";
		cout << a.size() << endl;
		for (int x : a)
			cout << x << ' ';
	}

	return 0;
}