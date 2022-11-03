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
#define endl '\n'
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
#ifdef LOCALFILE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	IOboost;

	rn(q);
	for (int j = 0; j < q; ++j) {
		rn(n);
		string s, t;
		cin >> s >> t;
		vi used1(26), used2(26);
		int flag = 0;
		fi(n)
			++used1[s[i] - 'a'];
		fi(n) 
			++used2[t[i] - 'a'];
		fi(26) {
			if (used1[i] > 1 || used2[i] > 1)
				flag = 1;
			if (used1[i] != used2[i]) {
				flag = -1;
				break;
			}
		}
		if (flag == -1) {
			cout << "NO\n";
			continue;
		}
		if (flag) {
			cout << "YES\n";
			continue;
		}
		int c1 = 0, c2 = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (s[i] > s[j])
					++c1;
				if (t[i] > t[j])
					++c2;
			}
		}
		if (c1 % 2 == c2 % 2)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}