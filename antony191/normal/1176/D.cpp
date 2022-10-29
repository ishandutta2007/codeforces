#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
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
#include <fstream>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#pragma comment(linker, "/STACK:256000000")
#pragma warning(disable:4996)

using namespace std;

typedef long long ll;
typedef long double ld;

const char el = '\n';
const int inf = 1e9;
const ll llinf = 1e18, mod = 998244353, md = 998244352;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define x first
#define y second

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return 1; } return 0; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return 1; } return 0; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << el; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(NULL));

const int N = 3000'000;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> lp(N);
	vector<int> pr;
	for (int i = 2; i < N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back(i);
		}
		for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] < N; ++j)
			lp[i * pr[j]] = pr[j];
	}
	int n;
	cin >> n;
	vector<int> b(n + n);
	forn(i, n + n) cin >> b[i];
	sort(all(b));
	multiset<int> q;
	vector<int> a;
	for (int i = n + n - 1; i >= 0; --i) {
		if (q.find(b[i]) != q.end()) {
			q.erase(q.find(b[i]));
			continue;
		}
		if (lp[b[i]] == b[i]) {
			auto j = lower_bound(all(pr), b[i]) - pr.begin() + 1;
			a.push_back(j);
			q.insert(j);
			continue;
		}
		q.insert(b[i] / lp[b[i]]);
		a.push_back(b[i]);
	}
	output(a);
#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}