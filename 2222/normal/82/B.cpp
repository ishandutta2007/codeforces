#include <algorithm>
#include <iostream>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <ctime>
#include <map>
#include <set>

using namespace std;

#define all(a)			(a).begin(), (a).end()
#define sz(a)			int((a).size())
#define FOR(i, a, b)	for (int i(a); i < b; ++i)
#define REP(i, n)		FOR(i, 0, n)
#define UN(v)			sort(all(v)), (v).erase(unique((v).begin(), (v).end()), (v).end())
#define CL(a, b)		memset(a, b, sizeof a)
#define pb				push_back
#define X				first
#define Y				second

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

int n, m;
vi a[222 * 222];
map<int, ll> h;
map<ll, vi> f;

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	srand(time(0));
	cin >> n;
	m = n * (n - 1) / 2;
	if (n == 2) {
		int k;
		scanf("%d", &k);
		vi s(k);
		REP (i, k) scanf("%d", &s[i]);
		printf("%d %d\n", 1, s[0]);
		printf("%d", sz(s) - 1);
		FOR (i, 1, k) printf(" %d", s[i]);
		puts("");
		return 0;
	}
	REP (i, m) {
		ll hsh = 0;
		REP (j, 13) hsh = hsh * 1000000123 + rand();
		int k;
		scanf("%d", &k);
		a[i].resize(k);
		REP (j, k) {
			scanf("%d", &a[i][j]);
			h[a[i][j]] ^= hsh;
		}
		UN(a[i]);
	}
	for (auto p : h) f[p.Y].pb(p.X);
	for (auto r : f) {
		auto &v = r.Y;
		printf("%d", sz(v));
		for (int x : v)
			printf(" %d", x);
		puts("");
	}
	return 0;
}