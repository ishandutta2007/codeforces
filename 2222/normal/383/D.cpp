#include <algorithm>
#include <iostream>
#include <assert.h>
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

const int mod = 1000000007;

int add(int x, int y) { return (x += y) < mod ? x : x - mod; }
int sub(int x, int y) { return (x -= y) < 0 ? x + mod : x; }

int F[1011][20001];
int n, a[1011];

int f(int x, int s) {
	if (x == n) return s == 0;
	int &res = F[x][s + 10000];
	if (res < 0) {
		res = (s == 0);
		res = add(res, f(x + 1, s + a[x]));
		res = add(res, f(x + 1, s - a[x]));
	}
	return res;
}

int main() {
    #ifdef LocalHost
    freopen("x.in", "r", stdin);
    #endif
    CL(F, -1);
	cin >> n;
	REP (i, n) cin >> a[i];
	int res = 0;
	REP (i, n) res = add(res, sub(f(i, 0), 1));
	cout << res << endl;
    return 0;
}