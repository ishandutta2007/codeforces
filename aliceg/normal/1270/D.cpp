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

#define pb push_back
#define mp make_pair
#define rn(n) int n; cin >> n
#define fi(n) for (int i = 0; i < (int)n; ++i)
#define fie(n) for (int i = 1; i <= (int)n; ++i)
#define fir(l, r) for (int i = (int)(l); i <= (int)(r); ++i)
#define fj(n) for (int j = 0; j < (int)n; ++j)
#define fje(n) for (int j = 1; j <= (int)n; ++j)
#define fjr(l, r) for (int j = (int)(l); j <= (int)(r); ++j)
#define fv(i, n) for (int i = 0; i < (int)n; ++i)
#define fve(i, n) for (int i = 1; i <= (int)n; ++i)
#define fvr(j, l, r) for (int j = (int)(l); j <= (int)(r); ++j)
#define sc(n) scanf("%d", &n)
#define scc(n) scanf("%c", &n)
#define scs(n) scanf("%s", &n)
#define scl(n) scanf("%l64d", &n)
//#define endl '\n'
#define sqr(x) ((x) * (x))
#define F first
#define S second
#define fll(x, a) memset(x, a, sizeof(x))
#define clr(x) memset(x, 0, sizeof(x))
#define IOboost ios_base::sync_with_stdio(false); cin.tie(NULL)
//#define int ll

#pragma warning (disable : 4996)
#pragma optimize ("gtsy", on)
//#pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <pii> vii;
typedef vector <char> vc;
typedef vector <ll> vll;
typedef vector <vll> vvll;

const ld EPS = 1e-8;
const int N = (int)1e5 + 10;
const int INF = (int)1e9 + 10;
const int MOD = (int)1e9 + 7;

signed main() {
//#ifdef LOCALFILE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif
	IOboost;
	
	int n, k;
	cin >> n >> k;
	if (k == 1) {
		cout << "! " << 1 << endl;
		return 0;
	}
	cout << "? ";
	fi(k)
		cout << i + 1 << ' ';
	cout << endl;
	vi a(n, -1);
	int p;
	cin >> p;
	--p;
	cin >> a[p];
	vi c(n, -1);
	int x = 0;
	if (p == 0)
		x = 1;
	c[x] = 0;
	fir(k, n - 1) {
		cout << "? ";
		fj(k) {
			if (j != x)
				cout << j + 1 << ' ';
			else
				cout << i + 1 << ' ';
		}
		cout << endl;
		int pos;
		cin >> pos;
		--pos;
		cin >> a[pos];
		if (pos != p)
			c[i] = 1;
		else
			c[i] = 0;
	}
	fi(k) {
		if (i == p || i == x)
			continue;
		cout << "? ";
		fj(k) {
			if (j != i)
				cout << j + 1 << ' ';
			else
				cout << k + 1 << ' ';
		}
		cout << endl;
		int pos;
		cin >> pos;
		--pos;
		cin >> a[pos];
		if (pos != p)
			c[i] = 1 - c[k];
		else
			c[i] = c[k];
	}
	int cnt = 0;
	fi(k) {
		if (c[i] == 0)
			++cnt;
	}
	cout << "? ";
	fi(k) {
		if (i == p)
			cout << k + 1 << ' ';
		else
			cout << i + 1 << ' ';
	}
	cout << endl;
	int pos;
	cin >> pos;
	--pos;
	cin >> a[pos];
	if ((a[pos] < a[p] && c[pos] == 1) || (a[pos] > a[p] && c[pos] == 0))
		cnt = k - cnt - 1;
	cout << "! " << cnt + 1;

	return 0;
}