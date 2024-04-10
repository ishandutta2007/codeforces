#pragma comment(linker, "/STACK:600000000")
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>

#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <stack>
#include <list>

#include <ctime>
#include <cassert>

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector <int> vi;
#define sz(s) int((s).size())

typedef long double ldb;
typedef long long int64;
typedef pair <int, int> pii;
typedef pair <double, double> pdd;

#define y0 wwwwwww
#define y1 qqqqqqq
#define next NEXT
#define prev PREV
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define ford(i, n) for (int i = (int) n - 1; i >= 0; i--)
#define seta(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define last(a) a[a.size() - 1]
#define mp make_pair
#define fs first
#define sc second

template <class T> T sqr(T x) { return x * x; }

double const pi = 3.1415926535897932384626433832795;
int const inf = (int) 1e9;
int64 const inf64 = (int64) 4e18;
const string name = "b";

const int NMAX = 105;

int n, k[NMAX], x[NMAX][NMAX], cnt[NMAX];

int main() {
//	freopen((name + ".in").data(), "r", stdin);
//	freopen((name + ".out").data(), "w", stdout);

	cin >> n;
	seta(cnt, 0);
	forn(i, n) {
		cin >> k[i];
		forn(j, k[i]) {
			cin >> x[i][j];
			cnt[x[i][j]]++;
		}
	}
	forn(i, n) {
		int ok = 1;
		forn(j, n)
			if (i != j) {
				int cross = 0;
				forn(f, k[i])
					forn(g, k[j])
						if (x[i][f] == x[j][g]) cross++;
				if (cross == k[j]) ok = 0;
			}
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}