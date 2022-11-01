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

int n;
int a[222222], b[222222];
bool r[222222];

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n;
	REP (i, n) scanf("%d", a + i);
	REP (i, n) scanf("%d", b + i);
	int q = -1u/2, d = 0;
	REP (i, n) {
		d += a[i] - b[i];
		q = min(q, d);
	}
	REP (i, n) {
		d += a[i] - b[i];
		if (q == d) r[(i + 1) % n] = true;
	}
	q = -1u/2;
	for (int i = n; i --> 0; ) {
		d += a[(i + 1) % n] - b[i];
		q = min(q, d);
	}
	for (int i = n; i --> 0; ) {
		d += a[(i + 1) % n] - b[i];
		if (q == d) r[i] = true;
	}
	vi res;
	REP (i, n) if (r[i]) res.pb(i);
	cout << sz(res) << endl;
	REP (i, sz(res)) {
		if (i) putchar(' ');
		printf("%d", res[i] + 1);
	}
	cout << endl;
	return 0;
}