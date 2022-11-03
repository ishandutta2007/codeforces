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

#define pb push_back
#define mp make_pair
#define rn(n) int n; cin >> n;
#define fi(n) for (int i = 0; i < n; ++i)
#define fie(n) for (int i = 1; i <= n; ++i)
#define fir(l, r) for (int i = (l); i <= (r); ++i)
#define fj(n) for (int j = 0; j < n; ++j)
#define fje(n) for (int j = 1; j <= n; ++j)
#define fjr(l, r) for (int j = (l); j <= (r); ++j)
#define fv(i, n) for (int i = 0; i < n; ++i)
#define fve(i, n) for (int i = 1; i <= n; ++i)
#define fvr(j, l, r) for (int j = (l); j <= (r); ++j)
#define sc(n) scanf("%d", &n)
#define scc(n) scanf("%c", &n)
#define scs(n) scanf("%s", &n)
#define scl(n) scanf("%lld", &n)
#define endl '\n'
#define sqr(x) ((x) * (x))
#define F first
#define S second
#define fll(x, a) memset(x, a, sizeof(x))
#define clr(x) memset(x, 0, sizeof(x))
#define IOboost ios_base::sync_with_stdio(false); cin.tie(NULL)
//#ifndef LOCALFILE
//#define _putchar_nolock putchar_unlocked
//#define _getchar_nolock getchar_unlocked
//#endif
#define int ll

#pragma warning (disable : 4996)
#pragma optimize ("gtsy", on)
//#pragma comment(linker, "/STACK:134217728")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <pii> vii;
typedef vector <char> vc;

const ld EPS = 1e-8;
const int INF = (int)1e9 + 10;
const int MOD = (int)1e9 + 7;
const int MOD1 = (int)1e9 + 9;
const int N = (int)2e5 + 10;
const int P = 47;

int n;
vii p(N);

pii hsh(vii& h, int l, int r) {
	return { (h[r].first - h[l].first * p[r - l].first % MOD + MOD) % MOD, (h[r].second - h[l].second * p[r - l].second % MOD1 + MOD1) % MOD1 };
}

pii rhsh(vii& h, int l, int r) {
	return { (h[l].first - h[r].first * p[r - l].first % MOD + MOD) % MOD, (h[l].second - h[r].second * p[r - l].second % MOD1 + MOD1) % MOD1 };
}

//void change(vii& a, int v, int L, int R, int i, pii x, bool f) {
//	if (R - L == 1) {
//		if (f)
//			a[v] = max(a[v], x);
//		else
//			a[v] = min(a[v], x);
//		return;
//	}
//	int M = (L + R) / 2;
//	if (i < M)
//		change(a, v * 2, L, M, i, x, f);
//	else
//		change(a, v * 2 + 1, M, R, i, x, f);
//	if (f)
//		a[v] = max(a[v * 2], a[v * 2 + 1]);
//	else
//		a[v] = min(a[v * 2], a[v * 2 + 1]);
//	return;
//}
//
//pii find(vii& a, int v, int L, int R, int l, int r, bool f) {
//	if (l <= L && R <= r)
//		return a[v];
//	if (l >= R || L >= r) {
//		if (f)
//			return { 0, 0 };
//		return { n + 1, 1 };
//	}
//	int M = (L + R) / 2;
//	pii x1 = find(a, v * 2, L, M, l, r, f);
//	pii x2 = find(a, v * 2 + 1, M, R, l, r, f);
//	if (f)
//		return max(x1, x2);
//	return min(x1, x2);
//}
//
//int solve(int l, int r, vii& minn, vii& maxx, int k) {
//	pii x1 = find(maxx, 1, 0, 1 << k, 0, l + 1, 1);
//	pii x2 = find(minn, 1, 0, 1 << k, r, 1 << k, 0);
//	return max((ll)0, max(2 * (x1.first - l) + x1.second, 2 * (r - x2.first) - x2.second));
//}
//
//string solve1(int l, int r, vii& minn, vii& maxx, int k, string& s) {
//	pii x1 = find(maxx, 1, 0, 1 << k, 0, l + 1, 1);
//	pii x2 = find(minn, 1, 0, 1 << k, r, 1 << k, 0);
//	int l1 = 2 * (x1.first - l) + x1.second, l2 = 2 * (r - x2.first) - x2.second;
//	if (l1 > l2 && l1 > 0)
//		return s.substr(l, l1);
//	else if (l2 > 0)
//		return s.substr(r - l2, l2);
//	return "";
//}

signed main() {
#ifdef LOCALFILE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	IOboost;

	p[0] = { 1, 1 };
	fie(N - 1) {
		p[i].first = (p[i - 1].first * P) % MOD;
		p[i].second = (p[i - 1].second * P) % MOD1;
	}
	rn(t);
	fj(t) {
		string s;
		cin >> s;
		n = s.length();
		vii h(n + 1), rh(n + 1);
		fi(n) {
			h[i + 1].first = (h[i].first * P + s[i]) % MOD;
			rh[n - i - 1].first = (rh[n - i].first * P + s[n - i - 1]) % MOD;
			h[i + 1].second = (h[i].second * P + s[i]) % MOD1;
			rh[n - i - 1].second = (rh[n - i].second * P + s[n - i - 1]) % MOD1;
		}
		int k = 0;
		while ((1 << k) < n)
			++k;
		vii minn(2 << k, { n + 1, 1 }), maxx(2 << k);
		vi a1(n), a2(n);
		fi(n) {
			int l = 0, r = min(i, n - i - 1) + 1;
			while (r - l > 1) {
				int m = (l + r) / 2;
				if (hsh(h, i - m, i + m + 1) == rhsh(rh, i - m, i + m + 1))
					l = m;
				else
					r = m;
			}
			a1[i] = l;/*
			if (i <= (n - 1) / 2)
				change(maxx, 1, 0, 1 << k, i - l, mp(i, 1), 1);
			if (i >= n / 2)
				change(minn, 1, 0, 1 << k, i + l + 1, mp(i, 1), 0);*/
		}
		fi(n) {
			int l = 0, r = min(i, n - i) + 1;
			while (r - l > 1) {
				int m = (l + r) / 2;
				if (hsh(h, i - m, i + m) == rhsh(rh, i - m, i + m))
					l = m;
				else
					r = m;
			}
			a2[i] = l;/*
			if (i <= n / 2)
				change(maxx, 1, 0, 1 << k, i - l, { i, 0 }, 1);
			if (i >= (n + 1) / 2)
				change(minn, 1, 0, 1 << k, i + l, { i, 0 }, 0);*/
		}
		string t = "";
		fi((n + 1) / 2) {
			int l = i, r = n - i;
			fvr(k, l, r - 1) {
				if (k - a1[k] <= l) {
					int r1 = k + (k - l) + 1;
					if (r1 <= r && r1 + n - r > t.length())
						t = s.substr(0, r1) + s.substr(r, n - r);
				}
				if (k + a1[k] + 1 >= r) {
					int l1 = k - (r - k - 1);
					if (l1 >= l && n - l1 + l > t.length())
						t = s.substr(0, l) + s.substr(l1, n - l1);
				}
				if (k - a2[k] <= l) {
					int r1 = k + (k - l);
					if (r1 <= r && r1 + n - r > t.length())
						t = s.substr(0, r1) + s.substr(r, n - r);
				}
				if (k + a2[k] >= r) {
					int l1 = k - (r - k);
					if (l1 >= l && n - l1 + l > t.length())
						t = s.substr(0, l) + s.substr(l1, n - l1);
				}
			}
			/*int res = 2 * i + solve(i, n - i, minn, maxx, k);
			if (res > ans) {
				ans = res;
				i1 = i;
			}*/
			if (s[i] != s[n - i - 1])
				break;
		}/*
		cout << s.substr(0, i1) + solve1(i1, n - i1, minn, maxx, k, s) + s.substr(n - i1, i1) << endl;*/
		cout << t << endl;
	}

	return 0;
}